// Copyright 2022 Marina Usova

#include <gtest.h>
#include "../lib_matrix/matrix.h"
/*
TEST(TDynamicMatrix, can_create_matrix_with_positive_length) {
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix) {
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one) {
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m2(5);

	EXPECT_EQ(m,m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory) {
	/*	TDynamicMatrix<int> m(2);
	std::cin >> m;
	TDynamicMatrix<int> m3(2);
	TDynamicMatrix<int> m2(m);
	m2 = m3;
	std::cin >> m2;
	std::cout << m2;

	EXPECT_NE(m, m2);

}

TEST(TDynamicMatrix, can_get_size) {
	TDynamicMatrix<int> m1(2);
	EXPECT_EQ(m1.size(), 2);
}

TEST(TDynamicMatrix, can_set_and_get_element) {
	TDynamicMatrix<int> m(1);
	ASSERT_NO_THROW(std::cin >> m);
	ASSERT_NO_THROW(std::cout << m[0] << std::endl);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index) {
	TDynamicMatrix<int> m(1);
	ASSERT_ANY_THROW(m[-1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index) {
	TDynamicMatrix<int> m(1);
	ASSERT_ANY_THROW(m[999999999999]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself) {
	TDynamicMatrix<int> m(2);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size) {
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m2(2);
	ASSERT_NO_THROW(m = m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size) {
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m2(4);
	EXPECT_EQ(m.size(), 4);
	ASSERT_NO_THROW(m = m2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size) {
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m2(4);
	ASSERT_NO_THROW(m = m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true) {
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m2(2);
	EXPECT_TRUE(m == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true) {
	TDynamicMatrix<int> m(2);
	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal) {
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m2(3);
	EXPECT_TRUE(m != m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size) {
	TDynamicVector<int> m(2);
	std::cin >> m;
	std::cout << m;
	TDynamicVector<int> m2(2);
	m2 = m * 2;
	std::cout << m2;
	m2 = m - m2;
	std::cout << m2;
	TDynamicMatrix<int> m(2);
	std::cin >> m;
	TDynamicMatrix<int> m2(2);
	std::cin >> m2;
	TDynamicMatrix<int> m3(2);
	std::cin >> m3;
	TDynamicMatrix<int> m4(2);
	m4 = m * 2;
	std::cout << m4;
	EXPECT_EQ(m4, m3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size) {
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m2(1);
	ASSERT_ANY_THROW(m + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size) {
	TDynamicMatrix<int> m(2);
	std::cin >> m;
	TDynamicMatrix<int> m2(2);
	std::cin >> m2;
	TDynamicMatrix<int> m3(2);
	std::cin >> m3;
	TDynamicMatrix<int> m4(2);
	m4 = m - m2;
	std::cout << m4;
	EXPECT_EQ(m4, m3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size) {
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m2(1);
	ASSERT_ANY_THROW(m - m2);
}
*/
