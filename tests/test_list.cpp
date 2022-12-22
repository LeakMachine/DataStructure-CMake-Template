// Copyright 2022 Vinokurov Ivan

#include <gtest.h>
#include "../lib_list/list.h"
/*TEST(test_lib_list, can_create_node) {
	ASSERT_NO_THROW(CNode<int> n1(2));
}
TEST(test_lib_list, can_create_list) {
	ASSERT_NO_THROW(CList<int> l1);
}
TEST(test_lib_list, can_set_next_node){
	CNode<int> n1(2);
	CNode<int> n2(3);
	ASSERT_NO_THROW(n1.setNext(&n2));
}
TEST(test_lib_list, can_push_front_to_list) {
	CList<int> l1;

	ASSERT_NO_THROW(l1.push_front(2));
	EXPECT_EQ(l1.size(), 1);
	EXPECT_FALSE(l1.isEmpty());
}
TEST(test_lib_list, can_push_back_to_list) {
	CList<int> l1;
	l1.push_front(2);
	ASSERT_NO_THROW(l1.push_back(2));
	EXPECT_EQ(l1.size(), 2);
	EXPECT_FALSE(l1.isEmpty());
}
TEST(test_lib_list, can_insert_to_list) {
	CList<int> l1;
	l1.push_front(2);
	l1.push_front(2);
	ASSERT_NO_THROW(l1.insert(0, 4));
	EXPECT_FALSE(l1.isEmpty());
	EXPECT_EQ(l1.size(), 3);
}
TEST(test_lib_list, can_pop_front_to_list) {
	CList<int> l1;
	l1.push_front(2);
	ASSERT_NO_THROW(l1.pop_front());
	EXPECT_TRUE(l1.isEmpty());
}
TEST(test_lib_list, can_pop_back_to_list) {
	CList<int> l1;
	l1.push_front(2);
	ASSERT_NO_THROW(l1.pop_back());
	EXPECT_TRUE(l1.isEmpty());
}
TEST(test_lib_list, cant_insert_in_wrong_pos_list) {
	CList<int> l1;
	ASSERT_ANY_THROW(l1.insert(-1, 4));
}
*/