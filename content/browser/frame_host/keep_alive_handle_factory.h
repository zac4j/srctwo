// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_BROWSER_FRAME_HOST_KEEP_ALIVE_HANDLE_FACTORY_H_
#define CONTENT_BROWSER_FRAME_HOST_KEEP_ALIVE_HANDLE_FACTORY_H_

#include "base/memory/ref_counted.h"
#include "content/common/frame.mojom.h"

namespace content {

class RenderProcessHost;

// A KeepAliveHandleFactory creates mojom::KeepAliveHandle. Each created
// handle prolongs the associated renderer's lifetime by using
// RenderProcessHost's KeepAliveRefCounts while alive.
// When a certain time (default: 30sec) passes after the factory is destroyed,
// all created handles are invalidated, which will result in render process
// shutdown.
class KeepAliveHandleFactory final {
 public:
  // |process_host->DisableKeepAliveRefCount()| must be false.
  explicit KeepAliveHandleFactory(RenderProcessHost* process_host);
  ~KeepAliveHandleFactory();

  void Create(mojom::KeepAliveHandleRequest request);

 private:
  class KeepAliveHandleImpl;
  class Context;

  scoped_refptr<Context> context_;

  DISALLOW_COPY_AND_ASSIGN(KeepAliveHandleFactory);
};

}  // namespace content

#endif  // CONTENT_BROWSER_FRAME_HOST_KEEP_ALIVE_HANDLE_FACTORY_H_
