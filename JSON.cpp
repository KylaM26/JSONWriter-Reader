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
JSONCpp::JSONObj::JSONObj() {
    this->key = "";
    this->isArray = true;
}
JSONCpp::JSONObj::JSONObj(const char* key) {
    this->key = key;
}
void JSONCpp::JSONObj::RenameKey(const char* key) {
    this->key = key;
}

void JSONCpp::JSONObj::AddChildObject(const char* key, const char* value) {
    this->keyValuePairs[key] = value;
}

void JSONCpp::JSONObj::AddChildObject(JSONObject object) {
    this->keyObjectPairs[object->Key()] = object;
}

void JSONCpp::JSONObj::AddChildObject(const char* key, JSONArray& arrays) {
    this->isArray = true;
    this->keyArrayPairs[key] = arrays;
}

const char* JSONCpp::JSONObj::Key() const {
    return this->key;
}

const std::map<std::string, std::string>& JSONCpp::JSONObj::KeyValuePairs() const {
    return this->keyValuePairs;
}

const std::map<std::string, JSONCpp::JSONObject>& JSONCpp::JSONObj::KeyObjectPairs() const {
    return this->keyObjectPairs;
}

const std::map<std::string, JSONCpp::JSONArray>& JSONCpp::JSONObj::KeyArrayPairs() const {
    return this->keyArrayPairs;
}

void JSONCpp::JSONObj::AddChildObjectToArray(const char* key, JSONCpp::JSONObject object) {
    this->isArray = true;
    this->keyArrayPairs[key].push_back(object);
}

void JSONCpp::JSONObj::SetIsArray(const bool b) {
    this->isArray = true;
}

const bool JSONCpp::JSONObj::IsArrayOfData() const {
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
