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
#include <memory>
#include <fstream>
#include "JSON.hpp"

namespace JSONCpp {
    class JSONReader {
    private:
        NestedJSON object;
        std::vector<std::shared_ptr<NestedJSON>> childrenObjets;
        std::string buffer;
        void Parse(NestedJSON& json);
        void ParseArrays(const char* key, NestedJSON& json);
        
        int index = 0;
    public:
        void ParseFile(const char* filepath);
        const NestedJSON& Object();
    };
};

#endif /* JSONReader_hpp */
