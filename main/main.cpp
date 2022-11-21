// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_example/example.h"
#include "../lib_stack/stack.h"

bool openingChar(char _chr) {
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
		if (!(openingChar(tempChar) && !(closingChar(tempChar)))) {
			throw std::logic_error("Wrong char");
		}
		if (openingChar(tempChar)) {
			tempStack.push(tempChar);
		}
		else if (i == 0 && closingChar(tempChar)) {
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

void main() {
	std::string testString("}(){}[])");

	if (isCorrect(testString)) {
		std::cout << "CORRECT!!!" << std::endl;
	}
	else {
		std::cout << "INCORRECT!!!" << std::endl;
	}
}
