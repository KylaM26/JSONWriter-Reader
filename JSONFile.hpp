//
//  JSONObject.hpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/2/20.
//

#ifndef JSONObject_hpp
#define JSONObject_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <queue>
#include <any>

#include "JSON.hpp"

// Only supports strings, maps, vectors
// Keys must have different names

namespace JSONCpp {
    class JSONFile {
    private:
        const char* key;
        const char* filePath;
        std::ofstream file;
        std::stringstream buffer;
        std::string contents;
        // Will store a key of any type
        std::queue<std::any> dataQueue;

        void WritePairToFile(const char* k, const char* v);
        void WritePairToFile(const NestedJSON& object);
//        void WritePairToFileWithoutKeys(const NestedJSON& object);
        void WritePairToFileWithoutKeys(const NestedJSON* object);
        
        void WriteFileHeader();
        void PrepareFileForWriting();
        void PrepareFileForClosing();
    public:
        // Must be initialized with a key and a path for writing
        JSONFile(const char* filePath);
        
        // Writes pair, must call update after queing is complete
        void QueueInPair(std::any pair);
        
        // Removes pair
        bool UnWrite(const char* key, const char* subKey);
        
        bool Update(); // Update must be called after writing and unwriting is complete
        
        void BeautifyJSON();
        
        ~JSONFile();
    };
    
};
#endif /* JSONObject_hpp */
