#pragma once
#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;
};

class List {
private:
	Node *head, *tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	void add(int index, int value) {
		if (index < 0) return;

		if (index == 0) {
			addInBegin(value);
		}
		else {
			Node *temp = head;
			for (int i = 0; i < index - 1; i++)
				temp = temp->next;
			Node *node = new Node;
			node->next = temp->next;
			temp->next = node;
			node->value = value;
		}
	}
	void addInBegin(int value) {
		Node *temp = new Node;
		temp->next = head;
		temp->value = value;
		head = temp;
		if (tail == NULL)
			tail = head;
	}
	void addInEnd(int value) {
		Node *temp = new Node;
		if (tail == NULL) {
			temp->value = value;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->value = value;
			temp->next = NULL;
			tail = temp;
		}
	}
	void remove(int index) {
		if (index <= 0) return;

		Node *temp = head;
		if (index > 1) {
			for (int i = 0; i < index - 2; i++)
				temp = temp->next;
			Node *node = temp->next;
			temp->next = temp->next->next;
			delete node;
		}
		else {
			Node *node = head;
			head = head->next;
			delete node;
		}
	}
	void clear() {
		while (head) {
			Node *temp = head->next;
			delete head;
			head = temp;
		}
	}
	int size() {
		int size = 0;
		Node *temp = head;
		while (temp != NULL) {
			temp = temp->next;
			size++;
		}
		return size;
	}
	int get(int index) {
		if (index <= 0) return 0;

		Node *temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		return temp->value;
	}
	void show() {
		Node *temp = head;
		cout << "List: ";
		while (temp != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};