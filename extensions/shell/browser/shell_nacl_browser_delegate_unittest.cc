// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "extensions/shell/browser/shell_nacl_browser_delegate.h"

#include "base/strings/pattern.h"
#include "base/strings/string_util.h"
#include "content/public/test/test_browser_context.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace extensions {

typedef testing::Test ShellNaClBrowserDelegateTest;

// Verifies that the returned version string has a valid format.
TEST_F(ShellNaClBrowserDelegateTest, VersionString) {
  content::TestBrowserContext browser_context;
  ShellNaClBrowserDelegate delegate(&browser_context);

  // Version should look like "1.2.3.4 (5)".
  std::string version = delegate.GetVersionString();
  EXPECT_TRUE(base::MatchPattern(version, "*.*.*.* (*)")) << "bad version "
                                                          << version;
}

}  // namespace extensions
