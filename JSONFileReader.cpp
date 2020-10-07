//
//  JSONReader.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/4/20.
//

#include "JSONFileReader.hpp"

void JSONCpp::JSONFileReader::ParseFile(const char* filepath) {
    std::ifstream file;
    
    file.open(filepath);
    
    std::string line;
    while (getline(file, line)) {
        this->buffer.append(line);
    }
    this->buffer.erase(remove(this->buffer.begin(), this->buffer.end(), ' '), this->buffer.end());
    file.close();
    
    
    this->Parse(this->object);
}

void JSONCpp::JSONFileReader::Parse(JSONObj& json) {
    std::string keyBuffer = "";
    std::string currentKey = "";
    std::string valueBuffer = "";

    bool keyWasFound = false, valueFound = false;
    
    for(; this->index < this->buffer.size(); this->index++) {
        char c = this->buffer[this->index];
        
        if(index == 0) {
            if(this->buffer[1] == '{' && c == '[')
                this->ParseArrays("", json);
        }
        
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
                std::shared_ptr<JSONObj> newJson = std::make_shared<JSONObj>(currentKey.c_str()); //new
                this->childrenObjets.push_back(newJson);
                json.AddChildObject(newJson);
                this->Parse(*newJson);
            } else if (nextChar == '[') {
                NameLessArrayOfData:
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

void JSONCpp::JSONFileReader::ParseArrays(const char* key, JSONCpp::JSONObj& json) {

    std::vector<std::shared_ptr<JSONObj>> arrayPointers;
    
    for(; this->index < this->buffer.size(); this->index++) {
        char c = this->buffer[this->index];
        
    
        if(c == '{') {
            std::shared_ptr<JSONObj> newArray = std::make_shared<JSONObj>();
            this->childrenObjets.push_back(newArray);
            arrayPointers.push_back(this->childrenObjets.back());
            this->Parse(*newArray);
        }

        if(c == ']') {
            json.AddChildObject(key, arrayPointers);
//            for(auto& arr : arrayPointers) {
//                json.AddChildObjectToArray(key, arr);
//            }
            return;
        }
    }
    
    
}

const JSONCpp::JSONObj& JSONCpp::JSONFileReader::Object() {
    return this->object;
}
