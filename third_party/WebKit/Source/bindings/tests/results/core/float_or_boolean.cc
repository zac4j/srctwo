// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format off
#include "float_or_boolean.h"

#include "bindings/core/v8/IDLTypes.h"
#include "bindings/core/v8/NativeValueTraitsImpl.h"
#include "bindings/core/v8/ToV8ForCore.h"

namespace blink {

FloatOrBoolean::FloatOrBoolean() : type_(SpecificTypeNone) {}

bool FloatOrBoolean::getAsBoolean() const {
  DCHECK(isBoolean());
  return boolean_;
}

void FloatOrBoolean::setBoolean(bool value) {
  DCHECK(isNull());
  boolean_ = value;
  type_ = SpecificTypeBoolean;
}

FloatOrBoolean FloatOrBoolean::fromBoolean(bool value) {
  FloatOrBoolean container;
  container.setBoolean(value);
  return container;
}

float FloatOrBoolean::getAsFloat() const {
  DCHECK(isFloat());
  return float_;
}

void FloatOrBoolean::setFloat(float value) {
  DCHECK(isNull());
  float_ = value;
  type_ = SpecificTypeFloat;
}

FloatOrBoolean FloatOrBoolean::fromFloat(float value) {
  FloatOrBoolean container;
  container.setFloat(value);
  return container;
}

FloatOrBoolean::FloatOrBoolean(const FloatOrBoolean&) = default;
FloatOrBoolean::~FloatOrBoolean() = default;
FloatOrBoolean& FloatOrBoolean::operator=(const FloatOrBoolean&) = default;

DEFINE_TRACE(FloatOrBoolean) {
}

void V8FloatOrBoolean::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, FloatOrBoolean& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState) {
  if (v8Value.IsEmpty())
    return;

  if (conversionMode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8Value))
    return;

  if (v8Value->IsBoolean()) {
    impl.setBoolean(v8Value.As<v8::Boolean>()->Value());
    return;
  }

  if (v8Value->IsNumber()) {
    float cppValue = NativeValueTraits<IDLFloat>::NativeValue(isolate, v8Value, exceptionState);
    if (exceptionState.HadException())
      return;
    impl.setFloat(cppValue);
    return;
  }

  {
    float cppValue = NativeValueTraits<IDLFloat>::NativeValue(isolate, v8Value, exceptionState);
    if (exceptionState.HadException())
      return;
    impl.setFloat(cppValue);
    return;
  }
}

v8::Local<v8::Value> ToV8(const FloatOrBoolean& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case FloatOrBoolean::SpecificTypeNone:
      return v8::Null(isolate);
    case FloatOrBoolean::SpecificTypeBoolean:
      return v8::Boolean::New(isolate, impl.getAsBoolean());
    case FloatOrBoolean::SpecificTypeFloat:
      return v8::Number::New(isolate, impl.getAsFloat());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

FloatOrBoolean NativeValueTraits<FloatOrBoolean>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  FloatOrBoolean impl;
  V8FloatOrBoolean::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exceptionState);
  return impl;
}

}  // namespace blink