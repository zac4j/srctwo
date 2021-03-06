// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <CoreFoundation/CoreFoundation.h>

#include "base/logging.h"
#include "base/mac/scoped_cftyperef.h"
#include "base/numerics/safe_conversions.h"
#include "base/strings/string16.h"
#include "base/strings/string_piece.h"
#include "base/strings/sys_string_conversions.h"
#include "net/base/net_string_util.h"

namespace net {

namespace {

bool CharsetToCFStringEncoding(const char* charset,
                               CFStringEncoding* encoding) {
  if (charset == kCharsetLatin1 || strcmp(charset, kCharsetLatin1) == 0) {
    *encoding = kCFStringEncodingISOLatin1;
    return true;
  }
  // TODO(mattm): handle other charsets? See
  // https://developer.apple.com/reference/corefoundation/cfstringbuiltinencodings?language=objc
  // for list of standard CFStringEncodings.

  return false;
}

}  // namespace

// This constant cannot be defined as const char[] because it is initialized
// by base::kCodepageLatin1 (which is const char[]) in net_string_util_icu.cc.
const char* const kCharsetLatin1 = "ISO-8859-1";

bool ConvertToUtf8(const std::string& text,
                   const char* charset,
                   std::string* output) {
  CFStringEncoding encoding;
  if (!CharsetToCFStringEncoding(charset, &encoding))
    return false;

  base::ScopedCFTypeRef<CFStringRef> cfstring(CFStringCreateWithBytes(
      kCFAllocatorDefault, reinterpret_cast<const UInt8*>(text.data()),
      base::checked_cast<CFIndex>(text.length()), encoding,
      false /* isExternalRepresentation */));
  if (!cfstring)
    return false;
  *output = base::SysCFStringRefToUTF8(cfstring.get());
  return true;
}

bool ConvertToUtf8AndNormalize(const std::string& text,
                               const char* charset,
                               std::string* output) {
  DCHECK(false) << "Not implemented yet.";
  return false;
}

bool ConvertToUTF16(const std::string& text,
                    const char* charset,
                    base::string16* output) {
  DCHECK(false) << "Not implemented yet.";
  return false;
}

bool ConvertToUTF16WithSubstitutions(const std::string& text,
                                     const char* charset,
                                     base::string16* output) {
  DCHECK(false) << "Not implemented yet.";
  return false;
}

}  // namespace net
