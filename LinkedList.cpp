#include <iostream>
using namespace std;

struct Node
{
	Node* next;
	int data;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class LinkedList
{
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtFront(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtEnd(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	bool insertIndexBased(int index, int data)
	{
		if (index < 0)
		{
			return false;
		}
		int currIndex = 1;
		Node* currNode = head;
		while (currNode && index > currIndex)
		{
			currNode = currNode->next;
			currIndex++;
		}
		if (index > 0 && currNode == NULL)
		{
			return false;
		}
		Node* newNode = new Node(data);
		if (index == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			newNode->next = currNode->next;
			currNode->next = newNode;
		}
		return false;
	}

	int search(int data)
	{
		Node* currNode = head;
		int currIndex = 0;
		while (currNode && currNode->data != data) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currIndex;
		return -1;
	}

	void deleteFront()
	{
		if (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}

	}

	int countNodes()
	{
		int numNodes = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			numNodes++;
		}
		return numNodes;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "Your linked list is empty." << endl;
		}
		else
		{
			Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;

		}
	}
};

int main()
{
	LinkedList obj;
	obj.display();

	obj.insertAtEnd(12);
	obj.insertAtEnd(99);
	obj.display();

	obj.insertAtFront(82);
	obj.insertAtFront(31);
	obj.display();

	cout << boolalpha;
	cout << std::boolalpha << obj.insertIndexBased(3, 5) << endl;

	cout << obj.search(5);
	cout << endl;

	obj.deleteFront();
	obj.display();

	cout <<"Count of Node: " <<  obj.countNodes() << endl;
}
