// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/installer/zucchini/buffer_sink.h"

namespace zucchini {

BufferSink::BufferSink(MutableBufferView buffer) : MutableBufferView(buffer) {}

}  // namespace zucchini
