// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "TestDictionary.h"

#include "bindings/tests/idls/core/TestInterfaceGarbageCollected.h"
#include "bindings/tests/idls/core/TestInterfaceImplementation.h"
#include "bindings/tests/idls/core/TestObject.h"
#include "core/dom/Element.h"
#include "core/dom/events/EventTarget.h"
#include "platform/wtf/Vector.h"

namespace blink {

TestDictionary::TestDictionary() {
  setDoubleOrStringMember(DoubleOrString::fromDouble(3.14));
  setEnumMember("foo");
  setLongMember(1);
  setOtherDoubleOrStringMember(DoubleOrString::fromString("default string value"));
  setRestrictedDoubleMember(3.14);
  setStringOrNullMember("default string value");
  setStringSequenceMember(Vector<String>());
  setTestInterfaceGarbageCollectedSequenceMember(HeapVector<Member<TestInterfaceGarbageCollected>>());
  setTestInterfaceSequenceMember(HeapVector<Member<TestInterfaceImplementation>>());
  setUnrestrictedDoubleMember(3.14);
}

TestDictionary::~TestDictionary() {}

TestDictionary::TestDictionary(const TestDictionary&) = default;

TestDictionary& TestDictionary::operator=(const TestDictionary&) = default;

void TestDictionary::setAnyInRecordMember(const Vector<std::pair<String, ScriptValue>>& value) {
  any_in_record_member_ = value;
  has_any_in_record_member_ = true;
}
void TestDictionary::setAnyMember(ScriptValue value) {
  any_member_ = value;
}
void TestDictionary::setBooleanMember(bool value) {
  boolean_member_ = value;
  has_boolean_member_ = true;
}
void TestDictionary::setCreateMember(bool value) {
  create_member_ = value;
  has_create_member_ = true;
}
void TestDictionary::setDictionaryMember(Dictionary value) {
  dictionary_member_ = value;
}
void TestDictionary::setDoubleOrNullMember(double value) {
  double_or_null_member_ = value;
  has_double_or_null_member_ = true;
}
void TestDictionary::setDoubleOrNullMemberToNull() {
  has_double_or_null_member_ = false;
}
void TestDictionary::setDoubleOrStringMember(const DoubleOrString& value) {
  double_or_string_member_ = value;
}
void TestDictionary::setDoubleOrStringSequenceMember(const HeapVector<DoubleOrString>& value) {
  double_or_string_sequence_member_ = value;
  has_double_or_string_sequence_member_ = true;
}
void TestDictionary::setElementOrNullMember(Element* value) {
  element_or_null_member_ = value;
}
void TestDictionary::setElementOrNullMemberToNull() {
  element_or_null_member_ = Member<Element>();
}
void TestDictionary::setEnumMember(const String& value) {
  enum_member_ = value;
}
void TestDictionary::setEnumSequenceMember(const Vector<String>& value) {
  enum_sequence_member_ = value;
  has_enum_sequence_member_ = true;
}
void TestDictionary::setEventTargetMember(EventTarget* value) {
  event_target_member_ = value;
}
void TestDictionary::setGarbageCollectedRecordMember(const HeapVector<std::pair<String, Member<TestObject>>>& value) {
  garbage_collected_record_member_ = value;
  has_garbage_collected_record_member_ = true;
}
void TestDictionary::setInternalDictionarySequenceMember(const HeapVector<InternalDictionary>& value) {
  internal_dictionary_sequence_member_ = value;
  has_internal_dictionary_sequence_member_ = true;
}
void TestDictionary::setIsPublic(bool value) {
  is_public_ = value;
  has_is_public_ = true;
}
void TestDictionary::setLongMember(int32_t value) {
  long_member_ = value;
  has_long_member_ = true;
}
void TestDictionary::setObjectMember(ScriptValue value) {
  object_member_ = value;
}
void TestDictionary::setObjectOrNullMember(ScriptValue value) {
  object_or_null_member_ = value;
}
void TestDictionary::setObjectOrNullMemberToNull() {
  object_or_null_member_ = ScriptValue();
}
void TestDictionary::setOtherDoubleOrStringMember(const DoubleOrString& value) {
  other_double_or_string_member_ = value;
}
void TestDictionary::setPrefixGetMember(ScriptValue value) {
  prefix_get_member_ = value;
}
void TestDictionary::setRecordMember(const Vector<std::pair<String, int8_t>>& value) {
  record_member_ = value;
  has_record_member_ = true;
}
void TestDictionary::setRestrictedDoubleMember(double value) {
  restricted_double_member_ = value;
  has_restricted_double_member_ = true;
}
void TestDictionary::setRuntimeMember(bool value) {
  runtime_member_ = value;
  has_runtime_member_ = true;
}
void TestDictionary::setStringMember(const String& value) {
  string_member_ = value;
}
void TestDictionary::setStringOrNullMember(const String& value) {
  string_or_null_member_ = value;
}
void TestDictionary::setStringOrNullMemberToNull() {
  string_or_null_member_ = String();
}
void TestDictionary::setStringSequenceMember(const Vector<String>& value) {
  string_sequence_member_ = value;
  has_string_sequence_member_ = true;
}
void TestDictionary::setTestInterface2OrUint8ArrayMember(const TestInterface2OrUint8Array& value) {
  test_interface_2_or_uint8_array_member_ = value;
}
void TestDictionary::setTestInterfaceGarbageCollectedMember(TestInterfaceGarbageCollected* value) {
  test_interface_garbage_collected_member_ = value;
}
void TestDictionary::setTestInterfaceGarbageCollectedOrNullMember(TestInterfaceGarbageCollected* value) {
  test_interface_garbage_collected_or_null_member_ = value;
}
void TestDictionary::setTestInterfaceGarbageCollectedOrNullMemberToNull() {
  test_interface_garbage_collected_or_null_member_ = Member<TestInterfaceGarbageCollected>();
}
void TestDictionary::setTestInterfaceGarbageCollectedSequenceMember(const HeapVector<Member<TestInterfaceGarbageCollected>>& value) {
  test_interface_garbage_collected_sequence_member_ = value;
  has_test_interface_garbage_collected_sequence_member_ = true;
}
void TestDictionary::setTestInterfaceMember(TestInterfaceImplementation* value) {
  test_interface_member_ = value;
}
void TestDictionary::setTestInterfaceOrNullMember(TestInterfaceImplementation* value) {
  test_interface_or_null_member_ = value;
}
void TestDictionary::setTestInterfaceOrNullMemberToNull() {
  test_interface_or_null_member_ = Member<TestInterfaceImplementation>();
}
void TestDictionary::setTestInterfaceSequenceMember(const HeapVector<Member<TestInterfaceImplementation>>& value) {
  test_interface_sequence_member_ = value;
  has_test_interface_sequence_member_ = true;
}
void TestDictionary::setTestObjectSequenceMember(const HeapVector<Member<TestObject>>& value) {
  test_object_sequence_member_ = value;
  has_test_object_sequence_member_ = true;
}
void TestDictionary::setUint8ArrayMember(NotShared<DOMUint8Array> value) {
  uint8_array_member_ = value.View();
}
void TestDictionary::setUnionInRecordMember(const HeapVector<std::pair<String, LongOrBoolean>>& value) {
  union_in_record_member_ = value;
  has_union_in_record_member_ = true;
}
void TestDictionary::setUnionWithTypedefs(const FloatOrBoolean& value) {
  union_with_typedefs_ = value;
}
void TestDictionary::setUnrestrictedDoubleMember(double value) {
  unrestricted_double_member_ = value;
  has_unrestricted_double_member_ = true;
}

DEFINE_TRACE(TestDictionary) {
  visitor->Trace(double_or_string_member_);
  visitor->Trace(double_or_string_sequence_member_);
  visitor->Trace(element_or_null_member_);
  visitor->Trace(event_target_member_);
  visitor->Trace(garbage_collected_record_member_);
  visitor->Trace(internal_dictionary_sequence_member_);
  visitor->Trace(other_double_or_string_member_);
  visitor->Trace(test_interface_2_or_uint8_array_member_);
  visitor->Trace(test_interface_garbage_collected_member_);
  visitor->Trace(test_interface_garbage_collected_or_null_member_);
  visitor->Trace(test_interface_garbage_collected_sequence_member_);
  visitor->Trace(test_interface_member_);
  visitor->Trace(test_interface_or_null_member_);
  visitor->Trace(test_interface_sequence_member_);
  visitor->Trace(test_object_sequence_member_);
  visitor->Trace(uint8_array_member_);
  visitor->Trace(union_in_record_member_);
  visitor->Trace(union_with_typedefs_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink