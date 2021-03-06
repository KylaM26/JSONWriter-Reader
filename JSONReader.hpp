//
//  JSONReader.hpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/4/20.
//

#ifndef JSONReader_hpp
#define JSONReader_hpp

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include "JSON.hpp"

namespace JSONCpp {
    class JSONFileReader {
    private:
        JSONObject object;
        std::vector<std::shared_ptr<JSONObject>> childrenObjets;
        std::string buffer;
        void Parse(JSONObject& json);
        void ParseArrays(const char* key, JSONObject& json);
        
        int index = 0;
    public:
        void ParseFile(const char* filepath);
        const JSONObject& Object();
    };
};

#endif /* JSONReader_hpp */
