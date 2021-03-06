// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8EventListenerInfo_h
#define V8EventListenerInfo_h

#include "platform/wtf/Vector.h"
#include "platform/wtf/text/AtomicString.h"
#include "v8/include/v8.h"

namespace blink {

class V8EventListenerInfo {
 public:
  V8EventListenerInfo(AtomicString event_type,
                      bool use_capture,
                      bool passive,
                      bool once,
                      v8::Local<v8::Object> handler,
                      int backend_node_id)
      : event_type(event_type),
        use_capture(use_capture),
        passive(passive),
        once(once),
        handler(handler),
        backend_node_id(backend_node_id) {}

  AtomicString event_type;
  bool use_capture;
  bool passive;
  bool once;
  v8::Local<v8::Object> handler;
  int backend_node_id;
};

using V8EventListenerInfoList = Vector<V8EventListenerInfo>;

}  // namespace blink

#endif  // V8EventListenerInfo_h
