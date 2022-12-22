// Copyright 2022 Marina Usova
#include <gtest.h>
#include "../lib_lsq/lsq.h"
TEST(test_lib_stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> s1(10));
}
TEST(test_lib_stack, cant_create_stack_if_negative_size) {
	ASSERT_ANY_THROW(Stack<int> s1(-10));
}
TEST(test_lib_stack, can_correctly_get_top) {
	Stack<int> s(5);
	s.push(4);
	s.push(5);
	int res;
	res = s.top();
	EXPECT_EQ(res, 5);
	EXPECT_FALSE(s.isEmpty());
}
TEST(test_lib_stack, can_correctly_use_pop) {
	Stack<int> s(5);
	s.push(3);
	int res;
	res = s.pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(s.isEmpty());
}
TEST(test_lib_stack, can_get_top) {
	Stack<int> s(5);
	s.push(3);
	ASSERT_NO_THROW(s.top());
}
TEST(test_lib_stack, cant_get_top_when_stack_empty) {
	Stack<int> s(5);
	ASSERT_ANY_THROW(s.top());
}
TEST(test_lib_stack, can_use_pop) {
	Stack<int> s(5);
	s.push(3);
	ASSERT_NO_THROW(s.pop());
}
TEST(test_lib_stack, cant_use_pop_when_stack_empty) {
	Stack<int> s(5);
	ASSERT_ANY_THROW(s.pop());
}

TEST(test_lib_queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> s1(10));
}
TEST(test_lib_queue, cant_create_queue_if_negative_size) {
	ASSERT_ANY_THROW(Queue<int> s1(-10));
}
TEST(test_lib_queue, can_correctly_get_top) {
	Queue<int> q(5);
	q.push(3);
	EXPECT_EQ(q.top(), 3);
	EXPECT_FALSE(q.isEmpty());
}
TEST(test_lib_queue, can_correctly_use_pop) {
	Queue<int> q(5);
	q.push(3);
	int res;
	res = q.pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(q.isEmpty());
}
TEST(test_lib_queue, can_push_if_full_and_has_empty_space_in_beginning) {
	Queue<int> q(3);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	ASSERT_NO_THROW(q.push(1));
}
TEST(test_lib_queue, can_correctly_push_if_full_and_has_empty_space_in_beginning) {
	Queue<int> q(3);
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
	Queue<int> q(5);
	q.push(3);
	ASSERT_NO_THROW(q.top());
}
TEST(test_lib_queue, cant_get_top_when_stack_empty) {
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.top());
}
TEST(test_lib_queue, can_use_pop) {
	Queue<int> q(5);
	q.push(3);
	ASSERT_NO_THROW(q.pop());
}
TEST(test_lib_queue, cant_use_pop_when_stack_empty) {
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.pop());
}
TEST(test_lib_queue_pr_in, can_use_priority_queue_in_correctly) {
	QueuePrIn<int> s(5);
	std::pair<int, int> val5(10, 1);
	std::pair<int, int> val3(7, 2);
	std::pair<int, int> val4(3, 2);
	std::pair<int, int> val2(5, 2);
	std::pair<int, int> val(6, 3);
	s.push(val5);
	s.push(val);
	s.push(val3);
	s.push(val4);
	s.push(val2);
	std::pair<int, int> res;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	res = s.top();
	EXPECT_EQ(res.first, 6);
	EXPECT_FALSE(s.isEmpty());
}
TEST(test_lib_queue_pr_out, can_use_priority_queue_out_correctly) {
	QueuePrOut<int> s(5);
	std::pair<int, int> val5(10, 1);
	std::pair<int, int> val3(7, 2);
	std::pair<int, int> val4(3, 2);
	std::pair<int, int> val2(5, 2);
	std::pair<int, int> val(6, 3);
	s.push(val3);
	s.push(val);
	s.push(val5);
	s.push(val4);
	s.push(val2);
	std::pair<int, int> res;
	res = s.pop();
	res = s.pop();
	res = s.pop();
	res = s.pop();
	EXPECT_EQ(res.first, 5);
	EXPECT_FALSE(s.isEmpty());
}

