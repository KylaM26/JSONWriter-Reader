//
//  JSONReader.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/4/20.
//

#include "JSONReader.hpp"

void JSONCpp::JSONReader::ParseFile(const char* filepath) {
    std::ifstream file;
    
    file.open(filepath);
    
    std::string line;
    while (getline(file, line)) {
        this->buffer.append(line);
    }
    
    file.close();
    
    
    this->Parse(this->object);
}

void JSONCpp::JSONReader::Parse(NestedJSON& json) {
    std::string keyBuffer = "";
    std::string currentKey = "";
    std::string valueBuffer = "";

    bool keyWasFound = false, valueFound = false;
    
    for(; this->index < this->buffer.size(); this->index++) {
        char c = this->buffer[this->index];
        
        if(keyWasFound) {
            if (c != '"')
                keyBuffer.push_back(c);
        }
        
        if(valueFound && c == '"') {
            json.AddChildObject(currentKey.c_str(), valueBuffer.c_str());
            valueBuffer = "";
        } else if(valueFound) {
            valueBuffer.push_back(c);
        }
        
        if(c == '"') { // If c qoute
            if(!valueFound)
                keyWasFound = keyWasFound == true ? false : true;
            valueFound = false;
        }
        
        if(keyBuffer != "" && c == ':') {
            currentKey = keyBuffer.c_str();
            char nextChar = this->buffer[this->index + 2];
            
            if(nextChar == '"') {
                valueFound = true;
            } else if (nextChar == '{') {
                std::shared_ptr<NestedJSON> newJson = std::make_shared<NestedJSON>(currentKey.c_str()); //new
                this->childrenObjets.push_back(newJson);
                json.AddChildObject(newJson.get());
                this->Parse(*newJson);
            } else if (nextChar == '[') {
//                std::shared_ptr<NestedJSON> newJson = std::make_shared<NestedJSON>(currentKey.c_str()); //new
//                newJson.get()->SetIsArray(true);
//                json.AddChildObject(newJson.get());
//                this->childrenObjets.push_back(newJson);
                this->ParseArrays(currentKey.c_str(), json);
            }
            
            keyBuffer = "";
            keyWasFound = false;
            this->index += 2; // So next round we will be at :, {, or [
        }
        
        
        
        if(c == '}' || c == ']')
            return;
    }
}

void JSONCpp::JSONReader::ParseArrays(const char* key, JSONCpp::NestedJSON& json) {

    std::vector<std::shared_ptr<NestedJSON>> arrayPointers;
    
    for(; this->index < this->buffer.size(); this->index++) {
        char c = this->buffer[this->index];
        
    
        if(c == '{') {
            std::shared_ptr<NestedJSON> newArray = std::make_shared<NestedJSON>();
            this->childrenObjets.push_back(newArray);
            arrayPointers.push_back(this->childrenObjets.back());
            this->Parse(*newArray);
        }

        if(c == ']') {
            for(auto& arr : arrayPointers) {
                json.AddChildObjectToArray(key, arr.get());
            }
            return;
        }
    }
    
    
}

const JSONCpp::NestedJSON& JSONCpp::JSONReader::Object() {
    return this->object;
}
