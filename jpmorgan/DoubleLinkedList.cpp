#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;

	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
public:
	Node* head;

	DoubleLinkedList() : head(nullptr) {}

	void insertFront(int data) {
		Node* newNode = new Node(data);
		if (head != nullptr) {
			newNode->next = head;
			head->prev = newNode;
		}
		head = newNode;
	}

	void insertEnd(int data) {
		Node* newNode = new Node(data);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}

	void deleteNode(int key) {
		if (head == nullptr)
			return;

		Node* temp = head;
		if (head->data == key) {
			head = head->next;
			if (head != nullptr)
				head->prev = nullptr;
			delete temp;
			return;
		}

		while (temp != nullptr && temp->data != key)
			temp = temp->next;

		if (temp == nullptr) return;

		if (temp->next != nullptr)
			temp->next->prev = temp->prev;
		if (temp->prev != nullptr)
			temp->prev->next = temp->next;

		delete temp;
	}

	void displayForward() {
		cout << "Forward: ";
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "null" << std::endl;
	}

	void displayBackward() {
		if (head == nullptr) return;
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		cout << "Backward: ";
		while (temp != nullptr) {
			cout << temp->data << "<-";
			temp = temp->prev;
		}

		cout << "null" << endl;
	}
};

int main() {
	DoubleLinkedList dll;

	dll.insertEnd(10);
	dll.insertEnd(20);
	dll.insertFront(5);
	dll.insertEnd(30);
	dll.insertFront(2);

	dll.displayForward();  // Expected: 2 <-> 5 <-> 10 <-> 20 <-> 30 <-> null
	dll.displayBackward(); // Expected: 30 <-> 20 <-> 10 <-> 5 <-> 2 <-> null

	dll.deleteNode(10);

	dll.displayForward();  // Expected: 2 <-> 5 <-> 20 <-> 30 <-> null

	return 0;
}