//
//  JSONObject.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/2/20.
//

#include "JSONFileWriter.hpp"

JSONCpp::JSONFileWriter::JSONFileWriter(const char* filePath) {
//    this->key = key;
    this->filePath = filePath;
    
    file.open(this->filePath, std::ios::trunc);
    this->WriteFileHeader(); // Writes file header
}

void JSONCpp::JSONFileWriter::QueueInPair(std::any pair) {
    this->dataQueue.push(pair);
}

void JSONCpp::JSONFileWriter::WritePairToFile(const std::string& k, const std::string& v) {
    this->buffer << "\"" << k << "\"" << " : " << "\"" << v << "\"";
}

void JSONCpp::JSONFileWriter::WritePairToFile(const JSONObj& object) {
    int counter = 0;
    
    if(!object.IsArrayOfData())
        this->buffer << "\"" << object.Key() << "\"" << " : " << "{\n";
    else
        this->buffer << "\"" << object.Key() << "\"" << " : " << "[\n";
    
    for(const auto& pair : object.KeyValuePairs()) {

         this->WritePairToFile(pair.first, pair.second);
         
         if(counter != object.KeyValuePairs().size() - 1 || !object.KeyObjectPairs().empty())
             this->buffer << ",\n";
         else  // If there is no child pointer dont add comma
             this->buffer << "\n";
        
        counter++;
    }
    
    counter = 0;
    
    for(const auto& pair : object.KeyObjectPairs()) {
        this->WritePairToFile(*pair.second);
        
        if(counter != object.KeyObjectPairs().size() - 1)
            this->buffer << "},\n";
        else
            this->buffer << "}\n";
        
        counter++;
    }
    
    counter = 0;
    
    for(const auto& maps : object.KeyArrayPairs()) {
        int counter2 = 0;
        for(const auto& map : maps.second) {
            this->WritePairToFileWithoutKeys(*map);
            
            if(counter2 != maps.second.size() - 1)
                this->buffer << "},\n";
            else
                this->buffer << "}\n";
            
            counter2++;
        }
//        const auto& secondPair = pair.second;
//        int counter2 = 0;
//
//        for(const auto& json : secondPair.second) {
//            this->WritePairToFileWithoutKeys(json);
//
//            if(counter2 != secondPair.second.size() - 1)
//                this->buffer << "},\n";
//            else
//                this->buffer << "}\n";
//
//            counter2++;
//        }
        
        if(counter != object.KeyArrayPairs().size() - 1)
            this->buffer <<  " ],\n";
        else
            this->buffer <<  " ]\n";
        
        counter++;

    }
    
}

void JSONCpp::JSONFileWriter::WritePairToFileWithoutKeys(const JSONObj& object) {
    this->buffer << "{\n";
    int counter = 0;
    
    for(const auto& pair : object.KeyValuePairs()) {
         this->WritePairToFile(pair.first, pair.second);
         
        if(counter != object.KeyValuePairs().size() - 1 || !object.KeyObjectPairs().empty())
            this->buffer << ",\n";
        else  // If there is no child pointer dont add comma
            this->buffer << "\n";
        
        counter++;
    }
    
    counter = 0;
    
    for(const auto& pair : object.KeyObjectPairs()) {
        this->WritePairToFile(*pair.second);
        
        if(!pair.second->IsArrayOfData()) {
        if (counter != object.KeyObjectPairs().size() - 1)
            this->buffer << "},\n";
        else
            this->buffer << "}\n";
        }
        
        
        counter++;
    }
}

void JSONCpp::JSONFileWriter::WriteFileHeader() {
    this->buffer << "{\n\n";
}

void JSONCpp::JSONFileWriter::PrepareFileForWriting() {
    this->contents = buffer.str();
    this->contents.pop_back(); // Removes }
    this->buffer = std::stringstream(this->contents);
}

void JSONCpp::JSONFileWriter::PrepareFileForClosing() {
    this->buffer << "\n}\n";
    this->contents.append(buffer.str());
    this->file << this->contents;
}


bool JSONCpp::JSONFileWriter::Update() {
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
            JSONObj json = std::any_cast<JSONObj>(pair);
            this->WritePairToFile(json);
        } catch (const std::bad_any_cast& err) {

        }
        
        this->dataQueue.pop(); // Pop top element
    }
    
    this->PrepareFileForClosing();
    file.close();
    
    return false;
}

void JSONCpp::JSONFileWriter::BeautifyJSON() {
    
}

JSONCpp::JSONFileWriter::~JSONFileWriter() {
    if(file.is_open())
        file.close();
}
