// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/threading/platform_thread.h"

#include <pthread.h>
#include <sched.h>

#include "base/threading/platform_thread_internal_posix.h"
#include "base/threading/thread_id_name_manager.h"
#include "base/tracked_objects.h"

namespace base {

namespace internal {

const ThreadPriorityToNiceValuePair kThreadPriorityToNiceValueMap[4] = {
    {ThreadPriority::BACKGROUND, 10},
    {ThreadPriority::NORMAL, 0},
    {ThreadPriority::DISPLAY, -8},
    {ThreadPriority::REALTIME_AUDIO, -10},
};

bool SetCurrentThreadPriorityForPlatform(ThreadPriority priority) {
  sched_param prio = {0};
  prio.sched_priority = ThreadPriorityToNiceValue(priority);
  return pthread_setschedparam(pthread_self(), SCHED_OTHER, &prio) == 0;
}

bool GetCurrentThreadPriorityForPlatform(ThreadPriority* priority) {
  sched_param prio = {0};
  int policy;
  if (pthread_getschedparam(pthread_self(), &policy, &prio) != 0) {
    return false;
  }
  *priority = NiceValueToThreadPriority(prio.sched_priority);
  return true;
}

}  // namespace internal

void InitThreading() {}

void TerminateOnThread() {}

size_t GetDefaultThreadStackSize(const pthread_attr_t& attributes) {
  return 0;
}

// static
void PlatformThread::SetName(const std::string& name) {
  // TODO(fuchsia): There's no system-level API to communicate a thread name
  // (for the debugger, etc.), so for now only set to our internal mechanisms.
  ThreadIdNameManager::GetInstance()->SetName(PlatformThread::CurrentId(),
                                              name);
  tracked_objects::ThreadData::InitializeThreadContext(name);
}

}  // namespace base
