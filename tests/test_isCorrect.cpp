#include <gtest.h>
#include "../lib_stack/stack.h"

/*bool openingChar(char _chr) {
	if (_chr == '(' || _chr == '[' || _chr == '{')
		return true;
	else
		return false;
}

bool closingChar(char _chr) {
	if (_chr == ')' || _chr == ']' || _chr == '}')
		return true;
	else
		return false;
}

bool matchChar(char _chr1, char _chr2) {
	if (_chr1 == '(' && _chr2 == ')') {
		return true;
	}
	else if (_chr1 == '{' && _chr2 == '}') {
		return true;
	}
	else if (_chr1 == '[' && _chr2 == ']') {
		return true;
	}
	return false;
}


bool isCorrect(std::string BracketsSequence) {
	Stack<char> tempStack(BracketsSequence.size());
	char tempChar;
	for (int i = 0; i < BracketsSequence.size(); i++) {
		tempChar = BracketsSequence[i];
		if (openingChar(tempChar)) {
			tempStack.push(tempChar);
		}
		else if (tempStack.isEmpty() && closingChar(tempChar)) {
			return false;
		}
		else if (matchChar(tempStack.top(), tempChar)) {
			tempStack.pop();
		}
		else {
			return false;
		}
	}
	if (!tempStack.isEmpty())
		return false;
	else
		return true;
}
TEST(test_main, correct_string_is_recognised) {
	std::string testString("[()](([]){})");

	EXPECT_TRUE(isCorrect(testString));
}
TEST(test_main, incorrect_string_is_recognised) {
	std::string testString("[{()}}]");

	EXPECT_FALSE(isCorrect(testString));
}

TEST(test_main, incorrect_string_is_recognised_because_stack_not_empty) {
	std::string testString("[{()}]{]");

	EXPECT_FALSE(isCorrect(testString));
}
TEST(test_main, incorrect_string_is_recognised_because_first_element_is_closing) {
	std::string testString("}(){}[]");

	EXPECT_FALSE(isCorrect(testString));
}
TEST(test_main, recognises_incorrect_character) {
	std::string testString("<}>(){}[]");

	ASSERT_ANY_THROW(isCorrect(testString));
}
TEST(test_main, incorrect_string_is_recognised_extra) {
	std::string testString("[()](([]){})[");

	EXPECT_FALSE(isCorrect(testString));
}
TEST(test_main, incorrect_string_is_recognised_extra_2) {
	std::string testString("[()](([]){})]");

	EXPECT_FALSE(isCorrect(testString));
}

*/