//
//  JSONObject.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/2/20.
//

#include "JSONFile.hpp"

JSONCpp::JSONFile::JSONFile(const char* key, const char* filePath) {
    this->key = key;
    this->filePath = filePath;
    
    file.open(this->filePath, std::ios::trunc);
    this->WriteFileHeader(); // Writes file header
}

void JSONCpp::JSONFile::QueueInPair(std::any pair) {
    this->dataQueue.push(pair);
}

void JSONCpp::JSONFile::WritePairToFile(const char* k, const char* v) {
    this->buffer << "\"" << k << "\"" << " : " << "\"" << v << "\"";
}

void JSONCpp::JSONFile::WritePairToFile(const NestedJSON& object) {

    int counter = 0;
    
    if(!object.IsArrayOfData())
        this->buffer << "\"" << object.Key() << "\"" << " : " << "{\n";
    else
        this->buffer << "\"" << object.Key() << "\"" << " : " << "[\n";
    
    for(const auto& pair : object.Objects()) {

         this->WritePairToFile(pair.first, pair.second);
         
         if(counter != object.Objects().size() - 1 || !object.ChildObjectPointers().empty())
             this->buffer << ",\n";
         else  // If there is no child pointer dont add comma
             this->buffer << "\n";
        
        counter++;
    }
    
    counter = 0;
    
    for(const auto& pair : object.ChildObjectPointers()) {
        this->WritePairToFile(*pair.second);
        
        if(counter != object.ChildObjectPointers().size() - 1)
            this->buffer << "},\n";
        else
            this->buffer << "}\n";
        
        counter++;
    }
    
    counter = 0;

    
    for(const auto& pair : object.MapObjects()) {
        
        const auto& secondPair = pair.second;
        int counter2 = 0;
        
        for(const auto& json : secondPair.second) {
            this->WritePairToFileWithoutKeys(json);

            if(counter2 != secondPair.second.size() - 1)
                this->buffer << "},\n";
            else
                this->buffer << "}\n";
            
            counter2++;
        }
        
        if(counter != object.MapObjects().size() - 1)
            this->buffer <<  " ],\n";
        else
            this->buffer <<  " ]\n";
        
        counter++;

    }
    
}

void JSONCpp::JSONFile::WritePairToFileWithoutKeys(const NestedJSON* object) {
    this->buffer << "{\n";
    int counter = 0;
    
    for(const auto& pair : object->Objects()) {
         this->WritePairToFile(pair.first, pair.second);
         
        if(counter != object->Objects().size() - 1 || !object->ChildObjectPointers().empty())
            this->buffer << ",\n";
        else  // If there is no child pointer dont add comma
            this->buffer << "\n";
        
        counter++;
    }
    
    counter = 0;
    
    for(const auto& pair : object->ChildObjectPointers()) {
        this->WritePairToFile(*pair.second);
        
        if(!pair.second->IsArrayOfData()) {
        if (counter != object->ChildObjectPointers().size() - 1)
            this->buffer << "},\n";
        else
            this->buffer << "}\n";
        }
        
        
        counter++;
    }
}

void JSONCpp::JSONFile::WriteFileHeader() {
    this->buffer << "{\n" << "\"" << this->key << "\"" << " : " << " {\n" << "}";
}

void JSONCpp::JSONFile::PrepareFileForWriting() {
    this->contents = buffer.str();
    this->contents.pop_back(); // Removes }
    this->buffer = std::stringstream(this->contents);
}

void JSONCpp::JSONFile::PrepareFileForClosing() {
    this->buffer << "}\n}";
    this->contents.append(buffer.str());
    this->file << this->contents;
}


bool JSONCpp::JSONFile::Update() {
    // Open file
    // Pop item out of queqe and cast it
    // After cast, write to file
    // close file
    this->PrepareFileForWriting();
    
    while(!this->dataQueue.empty()) { // While there are pairs registered in the queqe
        auto& pair = this->dataQueue.front(); // Get pair in front
        
        // Casting(Only supporting strings and maps for now)
        
        // First try string casting
        try {
            JSON jsonPair = std::any_cast<JSON>(pair);
            this->WritePairToFile(jsonPair.Key(), jsonPair.Value());
            
            if(this->dataQueue.size() != 1)
                this->buffer << ",\n";
            else
                this->buffer << "\n";
            
        } catch (const std::bad_any_cast& err) {

        }
        
        // Next try casting map type
        try {
            NestedJSON json = std::any_cast<NestedJSON>(pair);

            this->WritePairToFile(json);
//
//            if(this->dataQueue.size() != 1)
//                this->buffer << "h},\n";
//            else
//                this->buffer << "h}\n";
//
        } catch (const std::bad_any_cast& err) {

        }

        this->dataQueue.pop(); // Pop top element
    }
    
    this->PrepareFileForClosing();
    file.close();
    
    return false;
}

void JSONCpp::JSONFile::BeautifyJSON() {
    
}

JSONCpp::JSONFile::~JSONFile() {
    if(file.is_open())
        file.close();
}
