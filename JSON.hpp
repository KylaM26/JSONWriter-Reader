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
        std::map<std::string, std::string> objects;
        std::map<std::string, NestedJSON*> childObjects;
        std::map<std::string, std::vector<NestedJSON*>> mapObjects;
        bool isArray = false;
    public:
        NestedJSON();
        NestedJSON(const char* key);

        
        void RenameKey(const char* key);
        void AddChildObject(const char* key, const char* value);
        void AddChildObject(NestedJSON* object);
        void AddChildObject(const char* key, std::vector<NestedJSON*>& arrays);

        void AddChildObjectToArray(const char* key, NestedJSON* object);
        
        const char* Key() const;
        const std::map<std::string, std::string>& Objects() const;
        const std::map<std::string, NestedJSON*>& ChildObjectPointers() const;
        const std::map<std::string, std::vector<NestedJSON*>>& MapObjects() const;
        
        void SetIsArray(const bool b);
        const bool IsArrayOfData() const;
        
//        const char* ValueForKey(const char* key) const;
//        const NestedJSON* ObjectForKey(const char* key) const;
//        const NestedJSON* ArrayForKey(const char* key) const;
    };

};



#endif /* JSON_hpp */
