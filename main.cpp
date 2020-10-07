//
//  main.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/2/20.
//

#include "JSONFileWriter.hpp"
#include "JSONFileReader.hpp"
#include <vector>
#include <memory>

using namespace JSONCpp;

int main(int argc, const char * argv[]) {
    const char* path = "/Users/incrediblekyla/Documents/Documents\ -\ Kyla’s\ MacBook\ Pro/WorkSpace/Developer/C\:C++/JSONWriter/JSONWriter/JSONFiles/Students.json";
    JSONFileWriter jsonWriter = JSONFileWriter(path);
    
    JSONObject students = MakeJSONObject("student");
    
    const char* name = "Kyla Mae Wilson";
    const char* email = "TheRealKylaMae@gmail.com";
    const char* age = "21";
    const char* gender = "F";

    JSONArray studentObjects;
    
    for(int i = 0; i < 4; i++) {
        JSONObject studentObject = MakeJSONObject();
        
        studentObject->AddChildObject("name", name);
        studentObject->AddChildObject("email", email);
        studentObject->AddChildObject("age", age);
        studentObject->AddChildObject("gender", gender);
        
        studentObjects.push_back(studentObject);
    }


    
    jsonWriter.QueueInPair(students);
    jsonWriter.Update();
    
    JSONFileReader jsonReader;
    jsonReader.ParseFile(path);
    
    JSONObj mainObject = jsonReader.Object();


    system("pause");
    return 0;
}
