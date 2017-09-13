// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8TestInterfaceEventInitConstructor.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/IDLTypes.h"
#include "bindings/core/v8/NativeValueTraitsImpl.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8TestInterfaceEventInit.h"
#include "core/dom/ExecutionContext.h"
#include "core/frame/LocalDOMWindow.h"
#include "platform/bindings/RuntimeCallStats.h"
#include "platform/bindings/V8ObjectConstructor.h"
#include "platform/wtf/GetPtr.h"
#include "platform/wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8TestInterfaceEventInitConstructor::wrapperTypeInfo = {
    gin::kEmbedderBlink,
    V8TestInterfaceEventInitConstructor::domTemplate,
    V8TestInterfaceEventInitConstructor::Trace,
    V8TestInterfaceEventInitConstructor::TraceWrappers,
    nullptr,
    "TestInterfaceEventInitConstructor",
    &V8Event::wrapperTypeInfo,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
    WrapperTypeInfo::kIndependent,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in TestInterfaceEventInitConstructor.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& TestInterfaceEventInitConstructor::wrapper_type_info_ = V8TestInterfaceEventInitConstructor::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, TestInterfaceEventInitConstructor>::value,
    "TestInterfaceEventInitConstructor inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&TestInterfaceEventInitConstructor::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "TestInterfaceEventInitConstructor is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace TestInterfaceEventInitConstructorV8Internal {

static void readonlyStringAttributeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  TestInterfaceEventInitConstructor* impl = V8TestInterfaceEventInitConstructor::ToImpl(holder);

  V8SetReturnValueString(info, impl->readonlyStringAttribute(), info.GetIsolate());
}

static void isTrustedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  TestInterfaceEventInitConstructor* impl = V8TestInterfaceEventInitConstructor::ToImpl(holder);

  V8SetReturnValueBool(info, impl->isTrusted());
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TestInterfaceEventInitConstructor_ConstructorCallback");

  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::kConstructionContext, "TestInterfaceEventInitConstructor");

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  V8StringResource<> type;
  TestInterfaceEventInit testInterfaceEventInit;
  type = info[0];
  if (!type.Prepare())
    return;

  if (!IsUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
    exceptionState.ThrowTypeError("parameter 2 ('testInterfaceEventInit') is not an object.");

    return;
  }
  V8TestInterfaceEventInit::ToImpl(info.GetIsolate(), info[1], testInterfaceEventInit, exceptionState);
  if (exceptionState.HadException())
    return;

  TestInterfaceEventInitConstructor* impl = TestInterfaceEventInitConstructor::Create(type, testInterfaceEventInit);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->AssociateWithWrapper(info.GetIsolate(), &V8TestInterfaceEventInitConstructor::wrapperTypeInfo, wrapper);
  V8SetReturnValue(info, wrapper);
}

} // namespace TestInterfaceEventInitConstructorV8Internal

void V8TestInterfaceEventInitConstructor::readonlyStringAttributeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TestInterfaceEventInitConstructor_readonlyStringAttribute_Getter");

  TestInterfaceEventInitConstructorV8Internal::readonlyStringAttributeAttributeGetter(info);
}

void V8TestInterfaceEventInitConstructor::isTrustedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TestInterfaceEventInitConstructor_isTrusted_Getter");

  TestInterfaceEventInitConstructorV8Internal::isTrustedAttributeGetter(info);
}

static const V8DOMConfiguration::AccessorConfiguration V8TestInterfaceEventInitConstructorAccessors[] = {
    { "readonlyStringAttribute", V8TestInterfaceEventInitConstructor::readonlyStringAttributeAttributeGetterCallback, nullptr, V8PrivateProperty::kNoCachedAccessor, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kAllWorlds },

    { "isTrusted", V8TestInterfaceEventInitConstructor::isTrustedAttributeGetterCallback, nullptr, V8PrivateProperty::kNoCachedAccessor, static_cast<v8::PropertyAttribute>(v8::DontDelete | v8::ReadOnly), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kAllWorlds },
};

void V8TestInterfaceEventInitConstructor::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TestInterfaceEventInitConstructor_Constructor");

  if (!info.IsConstructCall()) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::ConstructorNotCallableAsFunction("TestInterfaceEventInitConstructor"));
    return;
  }

  if (ConstructorMode::Current(info.GetIsolate()) == ConstructorMode::kWrapExistingObject) {
    V8SetReturnValue(info, info.Holder());
    return;
  }

  TestInterfaceEventInitConstructorV8Internal::constructor(info);
}

static void installV8TestInterfaceEventInitConstructorTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8TestInterfaceEventInitConstructor::wrapperTypeInfo.interface_name, V8Event::domTemplate(isolate, world), V8TestInterfaceEventInitConstructor::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8TestInterfaceEventInitConstructor::constructorCallback);
  interfaceTemplate->SetLength(2);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register IDL constants, attributes and operations.
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate,
      signature, V8TestInterfaceEventInitConstructorAccessors, WTF_ARRAY_LENGTH(V8TestInterfaceEventInitConstructorAccessors));

  // Custom signature

  V8TestInterfaceEventInitConstructor::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interfaceTemplate);
}

void V8TestInterfaceEventInitConstructor::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  // Custom signature
}

v8::Local<v8::FunctionTemplate> V8TestInterfaceEventInitConstructor::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8TestInterfaceEventInitConstructorTemplate);
}

bool V8TestInterfaceEventInitConstructor::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8TestInterfaceEventInitConstructor::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TestInterfaceEventInitConstructor* V8TestInterfaceEventInitConstructor::ToImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

TestInterfaceEventInitConstructor* NativeValueTraits<TestInterfaceEventInitConstructor>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  TestInterfaceEventInitConstructor* nativeValue = V8TestInterfaceEventInitConstructor::ToImplWithTypeCheck(isolate, value);
  if (!nativeValue) {
    exceptionState.ThrowTypeError(ExceptionMessages::FailedToConvertJSValue(
        "TestInterfaceEventInitConstructor"));
  }
  return nativeValue;
}

}  // namespace blink