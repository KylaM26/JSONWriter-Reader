//
//  JSONReader.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/4/20.
//

#include "JSONReader.hpp"

void JSONCpp::JSONReader::Parse(const char* filepath) {
    std::ifstream file;
    
    file.open(filepath);
    file >> this->buffer;
    file.close();
    
    std::string keyBuffer = "";
    bool keyWasFound = false;
    
//    std::vector<const char*> keys;
    
    for(const auto& c : this->buffer) {
        if(keyWasFound) {
            keyBuffer.push_back(c);
        }
        
        if(c == '"') { // If c qoute
            keyWasFound = keyWasFound == true ? false : true;
        }
        
        if(keyBuffer != "" && c == '{') {
//            objects[keyBuffer] =
            keyBuffer = "";
        }
    }
}
