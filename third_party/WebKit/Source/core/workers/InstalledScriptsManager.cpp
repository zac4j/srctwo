// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/workers/InstalledScriptsManager.h"

#include "core/frame/csp/ContentSecurityPolicy.h"
#include "core/origin_trials/OriginTrialContext.h"
#include "platform/HTTPNames.h"

namespace blink {

InstalledScriptsManager::ScriptData::ScriptData(
    const KURL& script_url,
    String source_text,
    std::unique_ptr<Vector<char>> meta_data,
    std::unique_ptr<CrossThreadHTTPHeaderMapData> header_data)
    : script_url_(script_url),
      source_text_(std::move(source_text)),
      meta_data_(std::move(meta_data)) {
  headers_.Adopt(std::move(header_data));
}

ContentSecurityPolicyResponseHeaders
InstalledScriptsManager::ScriptData::GetContentSecurityPolicyResponseHeaders() {
  return ContentSecurityPolicyResponseHeaders(headers_);
}

String InstalledScriptsManager::ScriptData::GetReferrerPolicy() {
  return headers_.Get(HTTPNames::Referrer_Policy);
}

std::unique_ptr<Vector<String>>
InstalledScriptsManager::ScriptData::CreateOriginTrialTokens() {
  return OriginTrialContext::ParseHeaderValue(
      headers_.Get(HTTPNames::Origin_Trial));
}

}  // namespace blink
