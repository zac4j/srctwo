// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PROXY_CONFIG_IOS_PROXY_SERVICE_FACTORY_H_
#define COMPONENTS_PROXY_CONFIG_IOS_PROXY_SERVICE_FACTORY_H_

#include <memory>

#include "base/macros.h"
#include "components/proxy_config/proxy_config_export.h"

class PrefProxyConfigTracker;
class PrefService;

namespace net {
class NetLog;
class NetworkDelegate;
class ProxyConfigService;
class ProxyService;
class URLRequestContext;
}

class PROXY_CONFIG_EXPORT ProxyServiceFactory {
 public:
  // Creates a ProxyConfigService that delivers the system preferences.
  static std::unique_ptr<net::ProxyConfigService> CreateProxyConfigService(
      PrefProxyConfigTracker* tracker);

  // Creates a PrefProxyConfigTracker that tracks browser state preferences.
  static std::unique_ptr<PrefProxyConfigTracker>
  CreatePrefProxyConfigTrackerOfProfile(PrefService* browser_state_prefs,
                                        PrefService* local_state_prefs);

  // Creates a PrefProxyConfigTracker that tracks local state only. This tracker
  // should be used for the system request context.
  static std::unique_ptr<PrefProxyConfigTracker>
  CreatePrefProxyConfigTrackerOfLocalState(PrefService* local_state_prefs);

  // Create a proxy service.
  static std::unique_ptr<net::ProxyService> CreateProxyService(
      net::NetLog* net_log,
      net::URLRequestContext* context,
      net::NetworkDelegate* network_delegate,
      std::unique_ptr<net::ProxyConfigService> proxy_config_service,
      bool quick_check_enabled);

 private:
  DISALLOW_COPY_AND_ASSIGN(ProxyServiceFactory);
};

#endif  // COMPONENTS_PROXY_CONFIG_IOS_PROXY_SERVICE_FACTORY_H_
