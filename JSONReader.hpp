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
#include <fstream>
#include "JSON.hpp"

namespace JSONCpp {
    class JSONReader {
    private:
        std::map<const char*, NestedJSON> objects;
        
        std::string buffer;
    public:
        void Parse(const char* filepath);
    
    };

};

#endif /* JSONReader_hpp */
