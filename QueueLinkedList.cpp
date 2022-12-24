#include <iostream>
using namespace std;

struct Node
{
	int data; 
	Node* next;
	/*Node(int data)
	{
		this->data = data;
		next = NULL;
	}*/
};

class LinkedQueue
{
private:
	Node *queueFront;
	Node* queueRear;

public:
	LinkedQueue()
	{
		queueFront = NULL;
		queueRear = NULL;
	}
	bool isEmptyQueue()
	{
		return queueFront == NULL;
	}
	bool isFullQueue()
	{
		return false;
	}
	void initializeQueue()
	{
		Node* temp;
		while (queueFront != NULL)
		{
			temp = queueFront;
			queueFront = queueFront->next;
			delete temp;
		}
	}

	int front()
	{
		if (queueFront != NULL)
		{
			return queueFront->data;
		}
		throw"Queue is empty";
	}
	int back()
	{
		if (queueRear != NULL)
		{
			return queueRear->data;
		}
		throw"Queue is empty";
	}
	void addQueue(int data)
	{
		Node* newNode= new Node;
		newNode->data = data;
		newNode->next = NULL;
		if (queueFront == NULL)
		{
			queueFront = newNode;
			queueRear = newNode;
		}
		else
		{
			queueRear->next = newNode;
			queueRear = queueRear->next;
		}
	}

	void deleteQueue()
	{
		if (queueFront != NULL)
		{
			Node* temp = queueFront;
			queueFront = queueFront->next;
			if (queueFront == NULL)
			{
				queueRear = NULL;
			}
			delete temp;
		}
		else
		{
			cout << "Queue is empty." << endl;
		}
	}
	void print()
	{
		if (!isEmptyQueue())
		{
			Node* temp = queueFront;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
};

int main()
{
	LinkedQueue obj;
	obj.addQueue(12);
	obj.addQueue(83);
	obj.addQueue(42);
	obj.print();
	cout <<"Front: "<<  obj.front() << endl;
	cout <<"Back: " <<  obj.back() << endl;
	obj.deleteQueue();
	obj.print();
	obj.deleteQueue();
	obj.print();
}
