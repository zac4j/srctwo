// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "modules/webgl/WebGLCompressedTextureETC1.h"

#include "modules/webgl/WebGLRenderingContextBase.h"

namespace blink {

WebGLCompressedTextureETC1::WebGLCompressedTextureETC1(
    WebGLRenderingContextBase* context)
    : WebGLExtension(context) {
  context->AddCompressedTextureFormat(GL_ETC1_RGB8_OES);
}

WebGLExtensionName WebGLCompressedTextureETC1::GetName() const {
  return kWebGLCompressedTextureETC1Name;
}

WebGLCompressedTextureETC1* WebGLCompressedTextureETC1::Create(
    WebGLRenderingContextBase* context) {
  return new WebGLCompressedTextureETC1(context);
}

bool WebGLCompressedTextureETC1::Supported(WebGLRenderingContextBase* context) {
  Extensions3DUtil* extensions_util = context->ExtensionsUtil();
  return extensions_util->SupportsExtension(
      "GL_OES_compressed_ETC1_RGB8_texture");
}

const char* WebGLCompressedTextureETC1::ExtensionName() {
  return "WEBGL_compressed_texture_etc1";
}

}  // namespace blink
