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

JSONCpp::NestedJSON::NestedJSON(const char* key,  const std::map<const char*, const char*>& objects) {
    this->key = key;
    this->objects = objects;
}

JSONCpp::NestedJSON::NestedJSON(const char* key, std::map<const char*, std::pair<const char*, std::vector<NestedJSON*>>>& maps) {
    this->key = key;
    this->mapObjects = maps;
    this->isArray = true;
}

void JSONCpp::NestedJSON::AddChildObject(NestedJSON* object) {
    this->childObjects[object->Key()] = object;
}
//
//void JSONCpp::NestedJSON::AddChildObject(const std::pair<const char*, std::vector<NestedJSON*>>& object) {
//    this->mapObjects[object.first] = object;
//}

const char* JSONCpp::NestedJSON::Key() const {
    return this->key;
}

const std::map<const char*, const char*>& JSONCpp::NestedJSON::Objects() const {
    return this->objects;
}

const std::map<const char*, JSONCpp::NestedJSON*>& JSONCpp::NestedJSON::ChildObjectPointers() const {
    return this->childObjects;
}

const std::map<const char*, std::pair<const char*, std::vector<JSONCpp::NestedJSON*>>>& JSONCpp::NestedJSON::MapObjects() const {
    return this->mapObjects;
}

const bool JSONCpp::NestedJSON::IsArrayOfData() const {
    return this->isArray;
}

// JSON ARRAY
//JSONCpp::JSONArray::JSONArray(const char* key) {
//    this->key = key;
//}
//
//JSONCpp::JSONArray::JSONArray(const char* key, std::vector<NestedJSON>& maps) {
//    this->key = key;
//    this->maps = maps;
//}
//
//const char* JSONCpp::JSONArray::Key() const {
//    return this->key;
//}
//
//void JSONCpp::JSONArray::AddMap(const NestedJSON& map) {
//    this->maps.push_back(map);
//}
//
//const std::vector<JSONCpp::NestedJSON>& JSONCpp::JSONArray::GetMaps() const {
//    return this->maps;
//}
