//
//  JSON.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/4/20.
//

#include "JSON.hpp"

JSONCpp::JSON::JSON(const char* key, const char* value) {
    this->stringValuePair.first = key;
    this->stringValuePair.second = value;
}

const char* JSONCpp::JSON::Key() const {
    return this->stringValuePair.first;
}

const char* JSONCpp::JSON::Value() const {
    return this->stringValuePair.second;
}


// NEST JSON
JSONCpp::NestedJSON::NestedJSON() {
    this->key = "";
}
JSONCpp::NestedJSON::NestedJSON(const char* key) {
    this->key = key;
}
void JSONCpp::NestedJSON::RenameKey(const char* key) {
    this->key = key;
}
//
//JSONCpp::NestedJSON::NestedJSON(const char* key,  const std::map<const char*, const char*>& objects) {
//    this->key = key;
//    this->objects = objects;
//}
//
//JSONCpp::NestedJSON::NestedJSON(const char* key, std::map<const char*, std::pair<const char*, std::vector<NestedJSON*>>>& maps) {
//    this->key = key;
//    this->mapObjects = maps;
//    this->isArray = true;
//}

void JSONCpp::NestedJSON::AddChildObject(const char* key, const char* value) {
    this->objects[key] = value;
}

void JSONCpp::NestedJSON::AddChildObject(NestedJSON* object) {
    this->childObjects[object->Key()] = object;
}

void JSONCpp::NestedJSON::AddChildObject(const char* key, std::vector<NestedJSON*>& arrays) {
    this->isArray = true;
    this->mapObjects[key] = arrays;
}

const char* JSONCpp::NestedJSON::Key() const {
    return this->key;
}

const std::map<std::string, std::string>& JSONCpp::NestedJSON::Objects() const {
    return this->objects;
}

const std::map<std::string, JSONCpp::NestedJSON*>& JSONCpp::NestedJSON::ChildObjectPointers() const {
    return this->childObjects;
}

const std::map<std::string, std::vector<JSONCpp::NestedJSON*>>& JSONCpp::NestedJSON::MapObjects() const {
    return this->mapObjects;
}

void JSONCpp::NestedJSON::AddChildObjectToArray(const char* key, JSONCpp::NestedJSON* object) {
    this->mapObjects[key].push_back(object);
}

void JSONCpp::NestedJSON::SetIsArray(const bool b) {
    this->isArray = true;
}

const bool JSONCpp::NestedJSON::IsArrayOfData() const {
    return this->isArray;
}
//
//const char*  JSONCpp::NestedJSON::ValueForKey(const char* key) const {
//    
//}
//
//const JSONCpp::NestedJSON*  JSONCpp::NestedJSON::ObjectForKey(const char* key) const {
//    
//}
//
//const JSONCpp::NestedJSON*  JSONCpp::NestedJSON::ArrayForKey(const char* key) const {
//    
//}
