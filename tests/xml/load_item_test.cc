#include "xml/load_item.h"

#include <gtest/gtest.h>
#include <iostream>

using namespace mcpe_viz;

TEST(UnitLoadItem, TryAddNoId){
    pugi::xml_document itemList;
    auto item = itemList.append_child("item");
    item.append_attribute("id");
    int load_item_ret = load_item(itemList);
    ASSERT_EQ(load_item_ret,-1);
}

TEST(UnitLoadItem, TryAddNoName){
    pugi::xml_document xml_items;
    auto item = xml_items.append_child("item");
    item.append_attribute("id").set_value(1);
    item.append_attribute("name");
    int load_item_ret = load_item(xml_items);
    ASSERT_EQ(load_item_ret,-1);
}