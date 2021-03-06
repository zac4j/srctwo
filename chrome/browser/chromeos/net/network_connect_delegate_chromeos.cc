// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/net/network_connect_delegate_chromeos.h"

#include "chrome/browser/chromeos/enrollment_dialog_view.h"
#include "chrome/browser/chromeos/login/lock/screen_locker.h"
#include "chrome/browser/chromeos/net/network_state_notifier.h"
#include "chrome/browser/chromeos/sim_dialog_delegate.h"
#include "chrome/browser/ui/ash/system_tray_client.h"
#include "chrome/browser/ui/webui/chromeos/mobile_setup_dialog.h"

namespace chromeos {

namespace {

bool IsUIAvailable() {
  // UI is available when screen is unlocked.
  return !ScreenLocker::default_screen_locker() ||
         !ScreenLocker::default_screen_locker()->locked();
}

}  // namespace

NetworkConnectDelegateChromeOS::NetworkConnectDelegateChromeOS()
    : network_state_notifier_(new NetworkStateNotifier()) {}

NetworkConnectDelegateChromeOS::~NetworkConnectDelegateChromeOS() {}

void NetworkConnectDelegateChromeOS::ShowNetworkConfigure(
    const std::string& network_id) {
  if (!IsUIAvailable())
    return;
  SystemTrayClient::Get()->ShowNetworkConfigure(network_id);
}

void NetworkConnectDelegateChromeOS::ShowNetworkSettings(
    const std::string& network_id) {
  if (!IsUIAvailable())
    return;
  SystemTrayClient::Get()->ShowNetworkSettings(network_id);
}

bool NetworkConnectDelegateChromeOS::ShowEnrollNetwork(
    const std::string& network_id) {
  if (!IsUIAvailable())
    return false;
  return enrollment::CreateEnrollmentDialog(network_id,
                                            nullptr /* owning_window */);
}

void NetworkConnectDelegateChromeOS::ShowMobileSimDialog() {
  if (!IsUIAvailable())
    return;
  SimDialogDelegate::ShowDialog(nullptr /* owning_window */,
                                SimDialogDelegate::SIM_DIALOG_UNLOCK);
}

void NetworkConnectDelegateChromeOS::ShowMobileSetupDialog(
    const std::string& network_id) {
  if (!IsUIAvailable())
    return;
  MobileSetupDialog::ShowByNetworkId(network_id);
}

void NetworkConnectDelegateChromeOS::ShowNetworkConnectError(
    const std::string& error_name,
    const std::string& network_id) {
  network_state_notifier_->ShowNetworkConnectError(error_name, network_id);
}

void NetworkConnectDelegateChromeOS::ShowMobileActivationError(
    const std::string& network_id) {
  network_state_notifier_->ShowMobileActivationError(network_id);
}

}  // namespace chromeos
