//
//  main.cpp
//  JSONWriter
//
//  Created by Kyla Wilson on 10/2/20.
//

#include "JSONFile.hpp"
#include "JSONReader.hpp"

using namespace JSONCpp;

int main(int argc, const char * argv[]) {
    const char* path = "/Users/incrediblekyla/Documents/Documents\ -\ Kyla’s\ MacBook\ Pro/WorkSpace/Developer/C\:C++/JSONWriter/JSONWriter/JSONFiles/Player.json";
//    JSONFile object = JSONFile(path); // The file
//
//    NestedJSON students = NestedJSON("students"); // Students arr container
//
//    NestedJSON student = NestedJSON();
//    student.AddChildObject("name", "Kyla");
//    student.AddChildObject("age", "21");
//    student.AddChildObject("major", "ComputerScience");
//
//    NestedJSON classes = NestedJSON("classes");
//
//    NestedJSON _class = NestedJSON();
//    _class.AddChildObject("course-name", "Algorithm Analysis");
//    _class.AddChildObject("course-number", "CSC 123");
//    _class.AddChildObject("course-classification", "Senior");
//
//    NestedJSON classInfo = NestedJSON("course-info");
//    classInfo.AddChildObject("difficulty", "Medium");
//    classInfo.AddChildObject("subject", "Programming");
//    classInfo.AddChildObject("description", "Very fun class.");
//
//    _class.AddChildObject(&classInfo);
//
//    std::vector<NestedJSON*> classArr;
//    classArr.push_back(&_class);
//    classArr.push_back(&_class);
//
//    classes.AddChildObject("classes", classArr);
//    student.AddChildObject(&classes);
//
//    std::vector<NestedJSON*> usersArr;
//    usersArr.push_back(&student);
//    usersArr.push_back(&student);
//
//    students.AddChildObject("users", usersArr);
//
//    object.QueueInPair(JSON("version", "1.0"));
//    object.QueueInPair(students);
//    object.Update();
//
    JSONReader reader;
    reader.ParseFile(path);
    
    NestedJSON schoolObject = reader.Object();
    std::map<std::string, std::string> schoolData = schoolObject.Objects();
    std::cout << schoolData["school"] << std::endl;
    
   std::map<std::string, std::vector<NestedJSON*>> schoolArrays = schoolObject.MapObjects();

    std::vector<NestedJSON*> studentObjects = schoolArrays["students"];

    system("pause");
    return 0;
}


// PLAYER 1

//std::map<const char*, const char*> player1Info;
//player1Info["name"] = "Kyla";
//player1Info["age"] = "21";
//player1Info["status"] = "offline";
//
//std::map<const char*, const char*> playerGear1;
//playerGear1["gear-set-top"] =  "Diamond Shirt";
//playerGear1["gear-set-bottom"] =  "Leather Skirt";
//playerGear1["gear-set-cap"] = "Pink Beanie";
//
//NestedJSON gear1 = NestedJSON("player-gear-set", playerGear1);
//
//std::map<const char*, const char*> playerGearAccesories1;
//
//playerGearAccesories1["gear-set-accessory-charm"] = "Red Charm";
//playerGearAccesories1["gear-set-accessory-braclet"] = "Glowy Chain Braclet";
//playerGearAccesories1["gear-set-accessory-earrings"] = "Small Gold Hoops";
//
//NestedJSON gearAccessories1 = NestedJSON("player-gear-set-accessories", playerGearAccesories1);
//NestedJSON extra1 = NestedJSON("extra");
//
//gear1.AddChildObject(&gearAccessories1);
//gear1.AddChildObject(&extra1);
//
//NestedJSON player1 = NestedJSON("Player1", player1Info);
//
//player1.AddChildObject(&gear1);
////
////    // PLAYER 2
//std::map<const char*, const char*> player2Info;
//player2Info["name"] = "John";
//player2Info["age"] = "19";
//player2Info["status"] = "online";;
//
//std::map<const char*, const char*> playerGear2;
//playerGear2["gear-set-top"] =  "Diamond Shirt";
//playerGear2["gear-set-bottom"] =  "Leather Skirt";
//playerGear2["gear-set-cap"] = "Pink Beanie";
//
//NestedJSON gear2 = NestedJSON("player-gear-set", playerGear2);
//
//std::map<const char*, const char*> playerGearAccesories2;
//
//playerGearAccesories2["gear-set-accessory-charm"] = "Red Charm";
//playerGearAccesories2["gear-set-accessory-braclet"] = "Glowy Chain Braclet";
//playerGearAccesories2["gear-set-accessory-earrings"] = "Small Gold Hoops";
//
//NestedJSON gearAccessories2 = NestedJSON("player-gear-set-accessories", playerGearAccesories2);
//NestedJSON extra2 = NestedJSON("extra");
//
//gear2.AddChildObject(&gearAccessories2);
//gear2.AddChildObject(&extra2);
//
//NestedJSON player2 = NestedJSON("Player2", player2Info);
//player2.AddChildObject(&gear2);
//
//
//std::pair<const char*, std::vector<NestedJSON*>> playerObjects;
//std::vector<NestedJSON*> play;
//play.push_back(&player1);
//play.push_back(&player2);
//
//playerObjects.first = "users";
//playerObjects.second = play;
