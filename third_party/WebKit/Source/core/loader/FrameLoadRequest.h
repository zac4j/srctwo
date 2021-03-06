/*
 * Copyright (C) 2003, 2006, 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FrameLoadRequest_h
#define FrameLoadRequest_h

#include "core/dom/Document.h"
#include "core/dom/events/Event.h"
#include "core/loader/FrameLoaderTypes.h"
#include "platform/loader/fetch/ResourceLoaderOptions.h"
#include "platform/loader/fetch/SubstituteData.h"

namespace blink {

class HTMLFormElement;
class ResourceRequest;
class SubstituteData;

struct CORE_EXPORT FrameLoadRequest {
  STACK_ALLOCATED();

 public:
  explicit FrameLoadRequest(Document* origin_document);
  FrameLoadRequest(Document* origin_document, const ResourceRequest&);
  FrameLoadRequest(Document* origin_document,
                   const ResourceRequest&,
                   const AtomicString& frame_name);
  FrameLoadRequest(Document* origin_document,
                   const ResourceRequest&,
                   const SubstituteData&);
  FrameLoadRequest(Document* origin_document,
                   const ResourceRequest&,
                   const AtomicString& frame_name,
                   ContentSecurityPolicyDisposition);

  Document* OriginDocument() const { return origin_document_.Get(); }

  ResourceRequest& GetResourceRequest() { return resource_request_; }
  const ResourceRequest& GetResourceRequest() const {
    return resource_request_;
  }

  const AtomicString& FrameName() const { return frame_name_; }
  void SetFrameName(const AtomicString& frame_name) {
    frame_name_ = frame_name;
  }

  const SubstituteData& GetSubstituteData() const { return substitute_data_; }

  bool ReplacesCurrentItem() const { return replaces_current_item_; }
  void SetReplacesCurrentItem(bool replaces_current_item) {
    replaces_current_item_ = replaces_current_item;
  }

  ClientRedirectPolicy ClientRedirect() const { return client_redirect_; }
  void SetClientRedirect(ClientRedirectPolicy client_redirect) {
    client_redirect_ = client_redirect;
  }

  Event* TriggeringEvent() const { return triggering_event_.Get(); }
  void SetTriggeringEvent(Event* triggering_event) {
    triggering_event_ = triggering_event;
  }

  HTMLFormElement* Form() const { return form_.Get(); }
  void SetForm(HTMLFormElement* form) { form_ = form; }

  ShouldSendReferrer GetShouldSendReferrer() const {
    return should_send_referrer_;
  }
  void SetShouldSendReferrer(ShouldSendReferrer should_send_referrer) {
    should_send_referrer_ = should_send_referrer;
  }

  ShouldSetOpener GetShouldSetOpener() const { return should_set_opener_; }
  void SetShouldSetOpener(ShouldSetOpener should_set_opener) {
    should_set_opener_ = should_set_opener;
  }

  ContentSecurityPolicyDisposition ShouldCheckMainWorldContentSecurityPolicy()
      const {
    return should_check_main_world_content_security_policy_;
  }

 private:
  FrameLoadRequest(Document* origin_document,
                   const ResourceRequest&,
                   const AtomicString& frame_name,
                   const SubstituteData&,
                   ContentSecurityPolicyDisposition);

  Member<Document> origin_document_;
  ResourceRequest resource_request_;
  AtomicString frame_name_;
  SubstituteData substitute_data_;
  bool replaces_current_item_;
  ClientRedirectPolicy client_redirect_;
  Member<Event> triggering_event_;
  Member<HTMLFormElement> form_;
  ShouldSendReferrer should_send_referrer_;
  ShouldSetOpener should_set_opener_;
  ContentSecurityPolicyDisposition
      should_check_main_world_content_security_policy_;
};

}  // namespace blink

#endif  // FrameLoadRequest_h
