#include "xml/load_item.h"

#include <gtest/gtest.h>
#include <iostream>

using namespace mcpe_viz;

class LoadItemTest : public ::testing::Test {
protected:
    static pugi::xml_document itemList;

    virtual void TearDown() {
        itemList.remove_children();
    }
};

pugi::xml_document LoadItemTest::itemList;

TEST_F(LoadItemTest, UnitAddItem) {
    auto item = itemList.append_child("item");
    item.append_attribute("id").set_value(0x106);
    item.append_attribute("name").set_value("Arrow");
    auto variant = item.append_child("itemvariant");
    variant.append_attribute("name").set_value("Arrow");
    variant.append_attribute("extradata").set_value(0x0);

    int load_item_ret = load_item(itemList);
    
    ASSERT_EQ(load_item_ret,0);
}

TEST_F(LoadItemTest, UnitTryAddNoId){
    auto item = itemList.append_child("item");
    item.append_attribute("id");
    
    int load_item_ret = load_item(itemList);
    
    ASSERT_EQ(load_item_ret,-1);
}

TEST_F(LoadItemTest, UnitTryAddNoName){
    auto item = itemList.append_child("item");
    item.append_attribute("id").set_value(0x106);
    item.append_attribute("name");

    int load_item_ret = load_item(itemList);
    
    ASSERT_EQ(load_item_ret,-1);
}

TEST_F(LoadItemTest, UnitTryAddItemDuplicate) {
    auto item = itemList.append_child("item");
    item.append_attribute("id").set_value(0x106);
    item.append_attribute("name").set_value("Arrow");
    itemList.append_copy(item);

    int load_item_ret = load_item(itemList);
    
    ASSERT_EQ(load_item_ret,-1);
}

TEST_F(LoadItemTest, UnitTryAddItemBadVariantNoName){
    auto item = itemList.append_child("item");
    item.append_attribute("id").set_value(0x106);
    item.append_attribute("name").set_value("Arrow");
    auto variant = item.append_child("itemvariant");
    variant.append_attribute("name").set_value("");

    int load_item_ret = load_item(itemList);
    
    ASSERT_EQ(load_item_ret,-1);
}

TEST_F(LoadItemTest, UnitTryAddItemBadVariantNoExtraData){
    auto item = itemList.append_child("item");
    item.append_attribute("id").set_value(0x100);
    item.append_attribute("name").set_value("Iron Shovel");
    auto variant = item.append_child("itemvariant");
    variant.append_attribute("name").set_value("Arrow");
    variant.append_attribute("extradata").set_value("");

    int load_item_ret = load_item(itemList);
    
    ASSERT_EQ(load_item_ret,-1);
}

TEST_F(LoadItemTest, UnitTryAddItemDuplicateVariant){
    auto item = itemList.append_child("item");
    item.append_attribute("id").set_value(0x100);
    item.append_attribute("name").set_value("Iron Shovel");
    auto variant = item.append_child("itemvariant");
    variant.append_attribute("name").set_value("Arrow");
    variant.append_attribute("extradata").set_value(0x0);
    item.append_copy(variant);

    int load_item_ret = load_item(itemList);
    
    ASSERT_EQ(load_item_ret,-1);
}