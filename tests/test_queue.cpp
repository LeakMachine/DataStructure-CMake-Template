#include <gtest.h>
#include "../lib_queue/queue.h"

/*
TEST(test_lib_queue, can_create_queue) {
	ASSERT_NO_THROW(Queue s1(10));
}
TEST(test_lib_queue, cant_create_queue_if_negative_size) {
	ASSERT_ANY_THROW(Queue s1(-10));
}
TEST(test_lib_queue, can_correctly_get_top) {
	Queue q(5);
	q.push(3);
	int res;
	res = q.top();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(q.isEmpty());
}
TEST(test_lib_queue, can_correctly_use_pop) {
	Queue q(5);
	q.push(3);
	int res;
	res = q.pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(q.isEmpty());
}
TEST(test_lib_queue, can_push_if_full_and_has_empty_space_in_beginning) {
	Queue q(3);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	ASSERT_NO_THROW(q.push(1));
}
TEST(test_lib_queue, can_correctly_push_if_full_and_has_empty_space_in_beginning) {
	Queue q(3);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.push(1);
	int res;
	res = q.pop();
	EXPECT_EQ(res, 4);
	int res1;
	res = q.pop();
	EXPECT_EQ(res, 5);
	int res2;
	res = q.pop();
	EXPECT_EQ(res, 1);
	EXPECT_TRUE(q.isEmpty());
}
TEST(test_lib_queue, can_get_top) {
	Queue q(5);
	q.push(3);
	ASSERT_NO_THROW(q.top());
}
TEST(test_lib_queue, cant_get_top_when_stack_empty) {
	Queue q(5);
	ASSERT_ANY_THROW(q.top());
}
TEST(test_lib_queue, can_use_pop) {
	Queue q(5);
	q.push(3);
	ASSERT_NO_THROW(q.pop());
}
TEST(test_lib_queue, cant_use_pop_when_stack_empty) {
	Queue q(5);
	ASSERT_ANY_THROW(q.pop());
}
*/
