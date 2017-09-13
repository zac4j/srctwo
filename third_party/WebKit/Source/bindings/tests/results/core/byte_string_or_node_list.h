// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format off
#ifndef ByteStringOrNodeList_h
#define ByteStringOrNodeList_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/NativeValueTraits.h"
#include "bindings/core/v8/V8BindingForCore.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class NodeList;

class CORE_EXPORT ByteStringOrNodeList final {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  ByteStringOrNodeList();
  bool isNull() const { return type_ == SpecificTypeNone; }

  bool isByteString() const { return type_ == SpecificTypeByteString; }
  const String& getAsByteString() const;
  void setByteString(const String&);
  static ByteStringOrNodeList fromByteString(const String&);

  bool isNodeList() const { return type_ == SpecificTypeNodeList; }
  NodeList* getAsNodeList() const;
  void setNodeList(NodeList*);
  static ByteStringOrNodeList fromNodeList(NodeList*);

  ByteStringOrNodeList(const ByteStringOrNodeList&);
  ~ByteStringOrNodeList();
  ByteStringOrNodeList& operator=(const ByteStringOrNodeList&);
  DECLARE_TRACE();

 private:
  enum SpecificTypes {
    SpecificTypeNone,
    SpecificTypeByteString,
    SpecificTypeNodeList,
  };
  SpecificTypes type_;

  String byte_string_;
  Member<NodeList> node_list_;

  friend CORE_EXPORT v8::Local<v8::Value> ToV8(const ByteStringOrNodeList&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8ByteStringOrNodeList final {
 public:
  CORE_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, ByteStringOrNodeList&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const ByteStringOrNodeList&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, ByteStringOrNodeList& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, ByteStringOrNodeList& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<ByteStringOrNodeList> : public NativeValueTraitsBase<ByteStringOrNodeList> {
  CORE_EXPORT static ByteStringOrNodeList NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

template <>
struct V8TypeOf<ByteStringOrNodeList> {
  typedef V8ByteStringOrNodeList Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::ByteStringOrNodeList);

#endif  // ByteStringOrNodeList_h