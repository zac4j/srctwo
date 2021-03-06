// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ios/chrome/browser/bookmarks/bookmark_model_factory.h"

#include <utility>

#include "base/memory/ptr_util.h"
#include "base/memory/singleton.h"
#include "components/bookmarks/browser/bookmark_model.h"
#include "components/bookmarks/browser/bookmark_utils.h"
#include "components/bookmarks/browser/startup_task_runner_service.h"
#include "components/keyed_service/ios/browser_state_dependency_manager.h"
#include "components/prefs/pref_service.h"
#include "components/undo/bookmark_undo_service.h"
#include "ios/chrome/browser/bookmarks/bookmark_client_impl.h"
#include "ios/chrome/browser/bookmarks/startup_task_runner_service_factory.h"
#include "ios/chrome/browser/browser_state/browser_state_otr_helper.h"
#include "ios/chrome/browser/browser_state/chrome_browser_state.h"
#include "ios/chrome/browser/history/history_service_factory.h"
#include "ios/chrome/browser/undo/bookmark_undo_service_factory.h"
#include "ios/web/public/web_thread.h"

namespace ios {

// static
bookmarks::BookmarkModel* BookmarkModelFactory::GetForBrowserState(
    ios::ChromeBrowserState* browser_state) {
  return static_cast<bookmarks::BookmarkModel*>(
      GetInstance()->GetServiceForBrowserState(browser_state, true));
}

// static
bookmarks::BookmarkModel* BookmarkModelFactory::GetForBrowserStateIfExists(
    ios::ChromeBrowserState* browser_state) {
  return static_cast<bookmarks::BookmarkModel*>(
      GetInstance()->GetServiceForBrowserState(browser_state, false));
}

// static
BookmarkModelFactory* BookmarkModelFactory::GetInstance() {
  return base::Singleton<BookmarkModelFactory>::get();
}

BookmarkModelFactory::BookmarkModelFactory()
    : BrowserStateKeyedServiceFactory(
          "BookmarkModel",
          BrowserStateDependencyManager::GetInstance()) {
  DependsOn(ios::BookmarkUndoServiceFactory::GetInstance());
  DependsOn(ios::StartupTaskRunnerServiceFactory::GetInstance());
}

BookmarkModelFactory::~BookmarkModelFactory() {}

void BookmarkModelFactory::RegisterBrowserStatePrefs(
    user_prefs::PrefRegistrySyncable* registry) {
  bookmarks::RegisterProfilePrefs(registry);
}

std::unique_ptr<KeyedService> BookmarkModelFactory::BuildServiceInstanceFor(
    web::BrowserState* context) const {
  ios::ChromeBrowserState* browser_state =
      ios::ChromeBrowserState::FromBrowserState(context);
  std::unique_ptr<bookmarks::BookmarkModel> bookmark_model(
      new bookmarks::BookmarkModel(
          base::MakeUnique<BookmarkClientImpl>(browser_state)));
  bookmark_model->Load(
      browser_state->GetPrefs(),
      browser_state->GetStatePath(),
      ios::StartupTaskRunnerServiceFactory::GetForBrowserState(browser_state)
          ->GetBookmarkTaskRunner(),
      web::WebThread::GetTaskRunnerForThread(web::WebThread::UI));
  ios::BookmarkUndoServiceFactory::GetForBrowserState(browser_state)
      ->Start(bookmark_model.get());
  // TODO(crbug.com/703565): remove std::move() once Xcode 9.0+ is required.
  return std::move(bookmark_model);
}

web::BrowserState* BookmarkModelFactory::GetBrowserStateToUse(
    web::BrowserState* context) const {
  return GetBrowserStateRedirectedInIncognito(context);
}

bool BookmarkModelFactory::ServiceIsNULLWhileTesting() const {
  return true;
}

}  // namespace ios
