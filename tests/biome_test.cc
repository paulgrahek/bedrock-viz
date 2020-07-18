#include "minecraft/v2/biome.h"

#include <gtest/gtest.h>
#include <iostream>

using namespace mcpe_viz;

TEST(BiomeTest, AddExistingIDToBiomeList){
  BaseObject::IdType id = 0x00; //Ocean
  std::string name = "Ocean";
  Biome* biome = Biome::add(id,name);
  ASSERT_EQ(biome, nullptr);
}

TEST(BiomeTest, AddNewIDToBiomeList) {
  BaseObject::IdType id = 0x00; //Ocean
  std::string name = "New Ocean";
  Biome* biome = Biome::add(id,name);
  ASSERT_NE(biome, nullptr);
  ASSERT_EQ(biome->id,id);
  ASSERT_EQ(biome->name,name);
}
    
TEST(UnitBiomeTest, GetBiomeByID){
  
}

TEST(IntegrationBiomeTest, GetBiomeByName_Null){
  
}

void SetupBiome(){
  BaseObject::IdType id = 0x00; //Ocean
  std::string name = "Ocean";


}
