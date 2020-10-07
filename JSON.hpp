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
#include <memory>
namespace JSONCpp {

class JSONObj;

typedef std::vector<std::shared_ptr<JSONObj>> JSONArray;
typedef std::shared_ptr<JSONObj> JSONObject;

#define MakeJSONObject std::make_shared<JSONObj>
    class JSON {
    private:
        std::pair<const char*, const char*> stringValuePair;
    public:
        JSON(const char* key, const char* value);
        const char* Key() const;
        const char* Value() const;
    };

    class JSONObj {
    private:
        const char* key;
        std::map<std::string, std::string> keyValuePairs;
        std::map<std::string, JSONObject> keyObjectPairs;
        std::map<std::string, JSONArray> keyArrayPairs;
        bool isArray = false;
    public:
        JSONObj();
        JSONObj(const char* key);

        
        void RenameKey(const char* key);
        void AddChildObject(const char* key, const char* value);
        void AddChildObject(JSONObject object);
        void AddChildObject(const char* key, JSONArray& arrays);

        void AddChildObjectToArray(const char* key, JSONObject object);
        
        const char* Key() const;
        const std::map<std::string, std::string>& KeyValuePairs() const;
        const std::map<std::string, JSONObject>& KeyObjectPairs() const;
        const std::map<std::string, JSONArray>& KeyArrayPairs() const;
        
        void SetIsArray(const bool b);
        const bool IsArrayOfData() const;
    };





};



#endif /* JSON_hpp */
