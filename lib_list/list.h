// Copyright 2022 Vinokurov Ivan

#ifndef LIB_STACK_LIST_H_
#define LIB_STACK_LIST_H_
#include <list>
#include <iostream>

class CNode {
	int data;
	CNode* next;

public:
	CNode(int _data) {
		data = _data;
		next = nullptr;
	}
	void setNext(CNode* _next) {
		next = _next;
	}
	void print() {
		std::cout << data << " -> ";
	}

	friend class CList;
};

class CList {
	CNode* head;
	CNode* tail;

public:
	CList() {
		head = nullptr;
		tail = nullptr;
	}
	bool isEmpty() {
		if (head == nullptr)
			return true;
		else
			return false;
	}
	size_t size() {
		size_t len = 0;
		CNode* head_copy = head;
		while (head_copy != nullptr) {
			head_copy = head_copy->next;
			len++;
		}
		return len;
	}
	void push_back(int _data) {
		CNode* new_node = new CNode(_data);
		if (head == nullptr) {
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
	}
	void push_front(int _data) {
		CNode* new_node = new CNode(_data);
		if (head == nullptr) {
			head = new_node;
			tail = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
	}
	void insert(CNode* _pos, int _data) {
		if (_pos == nullptr)
			throw("can't insert in nullptr");
		else {
			CNode* new_node = new CNode(_data);
			new_node->next = _pos->next;
			_pos->next = new_node;
			if (new_node->next == nullptr) {
				tail = new_node;
			}
		}
	}

	int pop_front() {
		CNode* toRet = head;
		if (!(head == nullptr)) {
			CNode* toDel = head;
			head = head->next;
			delete toDel;
			return head->data;
		}
		if (head == nullptr) {
			tail = nullptr;
			return toRet->data;
		}
	}
	int pop_back() {
		CNode* toRet = tail;
		int temp = toRet->data;
		if (head != tail) {
			CNode* toDel = head;
			while (toDel->next != tail) {
				toDel = toDel->next;
			}
			delete tail;
			tail = toDel;
			return temp;
		}
		else {
			delete tail;
			delete head;
			return temp;
		}
	
	}

};


#endif