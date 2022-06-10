//Linked Queue By Mina Ashraf

#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* link;

	Node() {
		data = 0;
		link = NULL;
	}
};

class Queue {
private:
	Node* front;
	Node* back;

public:
	Queue() {
		front = back = NULL;
	}

	void isFull() {
		Node* newNode = new Node();
		if (newNode == NULL)
			cout << "Sorry, Queue is full\n";
	}

	bool isEmpty() {
		if (front == NULL && back == NULL)
			return true;
		else
			return false;
	}

	void enQueue(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		if (isEmpty())
			front = back = newNode;
		else {
			back->link = newNode;
			back = newNode;
		}
	}

	int deQueue() {
		int data;
		Node* del = front;
		if (isEmpty())
			data = -1;
		else if (front == back) {
			data = front->data;
			front = back = NULL;
			delete del;
		}
		else {
			data = del->data;
			front = front->link;
			delete del;
		}
		return data;
	}

	int getFront() {
		return front->data;
	}

	int getBack() {
		return back->data;
	}

	void display() {
		Node* temp = front;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->link;
		}
		cout << "\n";
	}

	bool isFound(int data) {
		Node* temp = front;
		if (isEmpty())
			return false;
		else {
			while (temp != NULL) {
				if (temp->data == data)
					return true;
				temp = temp->link;
			}
		}
		return false;
	}

	int count() {
		int counter = 0;
		Node* temp = front;
		while (temp != NULL) {
			counter++;
			temp = temp->link;
		}
		return counter;
	}

	void clear() {
		while (front != NULL)
			deQueue();
	}
};

int main() {
	Queue q;
	int data;
	int item;

	//insert
	cout << "Enter number of item\n";
	cin >> item;
	while (item) {
		cout << "Enter data to insert\n";
		cin >> data;
		q.enQueue(data);
		item--;
	}

	//display
	cout << "The queue:\n";
	q.display();

	//remove
	if (q.isEmpty())
		cout << "The Queue is empty.\n";
	else
		cout << q.deQueue() << " is removed\n";
	cout << "Queue after removed:\n";
	q.display();

	//search
	cout << "Enter data to search\n";
	cin >> data;
	if (q.isFound(data))
		cout << data << " is founded\n";
	else
		cout << data << " not found\n";

	//count
	cout << "Number of items is " << q.count() << "\n";

	//peek
	cout << q.getFront() << " is front\n";
	cout << q.getBack() << " is back\n";

	//clear
	q.clear();

	return 0;
}