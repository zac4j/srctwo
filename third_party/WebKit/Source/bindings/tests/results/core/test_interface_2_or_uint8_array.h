// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format off
#ifndef TestInterface2OrUint8Array_h
#define TestInterface2OrUint8Array_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/NativeValueTraits.h"
#include "bindings/core/v8/V8ArrayBufferView.h"
#include "bindings/core/v8/V8BindingForCore.h"
#include "bindings/core/v8/V8Uint8Array.h"
#include "core/CoreExport.h"
#include "core/typed_arrays/ArrayBufferViewHelpers.h"
#include "core/typed_arrays/FlexibleArrayBufferView.h"
#include "platform/heap/Handle.h"

namespace blink {

class TestInterface2;

class CORE_EXPORT TestInterface2OrUint8Array final {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  TestInterface2OrUint8Array();
  bool isNull() const { return type_ == SpecificTypeNone; }

  bool isTestInterface2() const { return type_ == SpecificTypeTestInterface2; }
  TestInterface2* getAsTestInterface2() const;
  void setTestInterface2(TestInterface2*);
  static TestInterface2OrUint8Array fromTestInterface2(TestInterface2*);

  bool isUint8Array() const { return type_ == SpecificTypeUint8Array; }
  NotShared<DOMUint8Array> getAsUint8Array() const;
  void setUint8Array(NotShared<DOMUint8Array>);
  static TestInterface2OrUint8Array fromUint8Array(NotShared<DOMUint8Array>);

  TestInterface2OrUint8Array(const TestInterface2OrUint8Array&);
  ~TestInterface2OrUint8Array();
  TestInterface2OrUint8Array& operator=(const TestInterface2OrUint8Array&);
  DECLARE_TRACE();

 private:
  enum SpecificTypes {
    SpecificTypeNone,
    SpecificTypeTestInterface2,
    SpecificTypeUint8Array,
  };
  SpecificTypes type_;

  Member<TestInterface2> test_interface_2_;
  Member<DOMUint8Array> uint8_array_;

  friend CORE_EXPORT v8::Local<v8::Value> ToV8(const TestInterface2OrUint8Array&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8TestInterface2OrUint8Array final {
 public:
  CORE_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, TestInterface2OrUint8Array&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const TestInterface2OrUint8Array&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, TestInterface2OrUint8Array& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, TestInterface2OrUint8Array& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<TestInterface2OrUint8Array> : public NativeValueTraitsBase<TestInterface2OrUint8Array> {
  CORE_EXPORT static TestInterface2OrUint8Array NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

template <>
struct V8TypeOf<TestInterface2OrUint8Array> {
  typedef V8TestInterface2OrUint8Array Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::TestInterface2OrUint8Array);

#endif  // TestInterface2OrUint8Array_h