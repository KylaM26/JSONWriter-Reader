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
    JSONFile object = JSONFile("player", path);
    
    
    std::map<const char*, std::pair<const char*, std::vector<NestedJSON*>>> playerObjects;

    // Player 1
    std::map<const char*, const char*> generalPlayerInfomation;
    generalPlayerInfomation["name"] = "Kyla";
    generalPlayerInfomation["level"] = "2";
    generalPlayerInfomation["classification"] = "Noobie";
    
    std::map<const char*, const char*> playerGearSet;
    playerGearSet["top"] = "Blue top";
    playerGearSet["bottom"] = "Green bottoms";
    playerGearSet["shoes"] = "Multicolored shoes";
    
    NestedJSON playerGear = NestedJSON("player-gear", playerGearSet);
    
    NestedJSON playerObjectOne = NestedJSON("player-1", generalPlayerInfomation);
    playerObjectOne.AddChildObject(&playerGear);
    
    
    std::map<const char*, std::pair<const char*, std::vector<NestedJSON*>>> playerAttacksObjects;
    
    std::map<const char*, const char*> playerAttackSet;
    playerAttackSet["attack-name"] = "Upper cut";
    playerAttackSet["damage"] = "10-20";
    playerAttackSet["critical-rate"] = "0";

    NestedJSON attackSet = NestedJSON("attack-set", playerAttackSet);
    
    std::vector<NestedJSON*> arrayOfAttacks;
    arrayOfAttacks.push_back(&attackSet);
    arrayOfAttacks.push_back(&attackSet);
    arrayOfAttacks.push_back(&attackSet);
    
    playerAttacksObjects["player-attacks"] = std::pair<const char*, std::vector<NestedJSON*>>("player-attacks", arrayOfAttacks);

    
    NestedJSON playerAttacks = NestedJSON("player-attacks", playerAttacksObjects);
   playerObjectOne.AddChildObject(&playerAttacks);
    
    std::vector<NestedJSON*> arrayOfPlayers;
    arrayOfPlayers.push_back(&playerObjectOne);
    arrayOfPlayers.push_back(&playerObjectOne);
    arrayOfPlayers.push_back(&playerObjectOne);
    
    playerObjects["users"] = std::pair<const char*, std::vector<NestedJSON*>>("users", arrayOfPlayers);
    
    NestedJSON usersArray = NestedJSON("users", playerObjects);
    
    object.QueueInPair(JSON("version", "1.0"));
    object.QueueInPair(usersArray);
    
    object.Update();
//
//    JSONReader reader;
//    NestedJSON data = reader.Parse(path);

    
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
