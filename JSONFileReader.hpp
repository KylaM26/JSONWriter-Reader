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
        JSONObj object;
        std::vector<std::shared_ptr<JSONObj>> childrenObjets;
        std::string buffer;
        void Parse(JSONObj& json);
        void ParseArrays(const char* key, JSONObj& json);
        
        int index = 0;
    public:
        void ParseFile(const char* filepath);
        const JSONObj& Object();
    };
};

#endif /* JSONReader_hpp */
