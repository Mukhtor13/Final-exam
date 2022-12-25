#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

class List {
	Node* head, * last;

public:
	List() {
		head = NULL;
		last = NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (head != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void insertAtLast(int data) {
		Node* newNode = new Node(data);
		if (!head) {
			head = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
	}
	int count()
	{
		int nodeNumber = 0;
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			Node* temp = head;
			while (temp != NULL)
			{
				temp = temp->next;
				nodeNumber++;
			}
			return nodeNumber;
		}
	}
	int topStack()
	{
		if (head != NULL)
		{
			return head->data;
		}
		throw"Stack is empty.";
	}
	void dleteStack()
	{
		if (head != NULL)
		{
			Node* temp = head;
			head = temp->next;
			delete temp;
		}
	}
	void printAll() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " " ;
			temp = temp->next;
		}
		cout << endl;
	}
	
};


int main() {
	List obj;
	cout << "Stack is empty: " << boolalpha << obj.isEmpty() << endl;
	cout << "Stack is full:  " << boolalpha << obj.isFull() << endl;
	cout << "Insert 12,63,84,75,24 to stack: " << endl;
	obj.insertAtLast(12);
	obj.insertAtLast(63);
	obj.insertAtLast(84);
	obj.insertAtLast(75);
	obj.insertAtLast(24);
	cout << "all Stack : ";
	obj.printAll();
	cout << "top element of stack: " << obj.topStack() << endl;
	cout << "count of stack: " << obj.count() << endl;
	cout << "delete item of stack " << endl;
	obj.dleteStack();
	cout << "all stack: ";
	obj.printAll();

	return 0;
}
