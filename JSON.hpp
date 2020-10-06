//
//  JSON.hpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/4/20.
//

#ifndef JSON_hpp
#define JSON_hpp

#include <iostream>
#include <vector>
#include <map>

namespace JSONCpp {
class JSONArray;

class NestedJSON;

    class JSON {
    private:
        std::pair<const char*, const char*> stringValuePair;
    public:
        JSON(const char* key, const char* value);
        const char* Key() const;
        const char* Value() const;
    };

    class NestedJSON {
    private:
        const char* key;
        std::map<const char*, const char*> objects;
        std::map<const char*, NestedJSON*> childObjects;
        std::map<const char*, std::vector<NestedJSON*>> mapObjects;
        bool isArray = false;
    public:
        NestedJSON();
        NestedJSON(const char* key);
//        NestedJSON(const char* key, const std::map<const char*, const char*>& objects);
//        NestedJSON(const char* key, std::map<const char*, std::pair<const char*, std::vector<NestedJSON*>>>& maps);
        
        void AddChildObject(const char* key, const char* value);
        void AddChildObject(NestedJSON* object);
        void AddChildObject(const char* key, std::vector<NestedJSON*>& arrays);
//        void AddChildObject(const std::pair<const char*, std::vector<NestedJSON*>>& object);
        
        const char* Key() const;
        const std::map<const char*, const char*>& Objects() const;
        const std::map<const char*, NestedJSON*>& ChildObjectPointers() const;
        const std::map<const char*, std::vector<NestedJSON*>>& MapObjects() const;
        
        const bool IsArrayOfData() const;
    };

//    class JSONArray {
//    private:
//        const char* key;
//        std::map<const char*, const char*> pairs;
//        std::map<const char*, NestedJSON*> childMaps;
//        std::map<const char*, std::vector<NestedJSON>> maps;
//    public:
//        JSONArray(const char* key);
//        JSONArray(const char* key, std::vector<NestedJSON>& maps);
//        const char* Key() const;
//        void AddMap(const NestedJSON& map);
//        const std::vector<NestedJSON>& GetMaps() const;
//    };
};



#endif /* JSON_hpp */
