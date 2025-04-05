#include <iostream>

using namespace std;
class LinkedListLoop {
public:
	struct Node {
		int data;
		Node* next;
		Node(int val) : data(val), next(nullptr) {}
	};

	Node* head;

	LinkedListLoop() : head(nullptr) {}

	void createLoop(int position) {
		Node* temp = head;
		Node* loopNode = nullptr;
		int count = 1;

		while (temp->next != nullptr) {
			if (count == position) {
				loopNode = temp;
			}
			temp = temp->next;
			count++;
		}

		if (loopNode != nullptr) {
			temp->next = loopNode; // Create the loop
		}
	}

	void append(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
			return;
		}

		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	void printList() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "null" << endl;
	}

	void findLoopStart(Node* meetingPoint) {
		Node* start = head;

		while (start != meetingPoint) {
			start = start->next;
			meetingPoint = meetingPoint->next;
		}

		cout << "Loop starts at node with data " << start->data << endl;
	}

	bool detectedLoop() {
		Node* slow = head;
		Node* fast = head;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				cout << "Loop detected. Start of the loop" << endl;
				findLoopStart(slow);
				return true;
			}
		}

		return false;
	}
};

int main() {
	LinkedListLoop list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);

	cout << "original list" << endl;
	list.printList();

	list.createLoop(3);

	if (!list.detectedLoop())
		cout << "No loop detected." << endl;

	return 0;
}
	
