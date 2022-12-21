#include <iostream>
#include <cassert>
using namespace std;

struct BinaryNode
{
	int data;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree
{
	BinaryNode* root;
public:
	BinaryTree()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		root = NULL;
	}

	void preOrderTraversal()
	{
		preOrder(root);
	}
	void inOrderTraversal()
	{
		inOrder(root);
	}
	void postOrderTraversal()

	{
		postOrder(root);
	}
	int treeHeight()
	{
		return height(root);
	}
	int treeNodeCount()
	{
		nodeCount(root);
	}
	int treeLeavesCount()
	{
		leavesCount(root);
	}
	~BinaryTree()
	{
		destroy(root);
	}

	void insert(int insertNum)
	{
		BinaryNode* curr;
		BinaryNode* trailCurr = NULL;
		BinaryNode* newNode = new BinaryNode(insertNum);

		assert(newNode != NULL);
		if (root == NULL)
		{
			root = newNode;
		}
		else
		{
			curr = root;
			while (curr != NULL)
			{
				trailCurr = curr;
				if (curr->data == insertNum)
				{
					cout << "The insert item is already in the list. Duplication are not allowed.";
					return;
				}
				else if (curr->data > insertNum)
				{
					curr = curr->left;
				}
				else
				{
					curr = curr->right;
				}
			}
			if (trailCurr->data > insertNum)
			{
				trailCurr->left = newNode;
			}
			else
			{
				trailCurr->right = newNode;
			}
		}
	}

private:
	void preOrder(BinaryNode* p)
	{
		if (p != NULL)
		{
			cout << p->data << " ";
			preOrder(p->left);
			preOrder(p->right);
		}
	}

	void inOrder(BinaryNode* p)
	{
		if (p != NULL)
		{
			inOrder(p->left);
			cout << p->data << " ";
			inOrder(p->right);
		}
	}

	void postOrder(BinaryNode* p)
	{
		if (p != NULL)
		{
			postOrder(p->left);
			postOrder(p->right);
			cout << p->data << " ";
		}
	}

	int maxFunction(int a, int b)
	{
		if (a >= b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}

	int height(BinaryNode* p)
	{
		if (p == NULL)
		{
			return 0;
		}
		else
		{
			return 1 + maxFunction(height(p->left), height(p->right));
		}
	}

	int nodeCount(BinaryNode* p)
	{
		if (p == NULL)
		{
			return 0;
		}
		else
		{
			return 1 + nodeCount(p->left) + nodeCount(p->right);
		}
	}

	int leavesCount(BinaryNode* p)
	{
		if (root = NULL)
		{
			return 0;
		}
		if (p->left == NULL && p->right == NULL)
		{
			return 1;
		}
		else
		{
			return leavesCount(p->left) + leavesCount(p->right);
		}
	}

	void destroy(BinaryNode* p)
	{
		if (root != NULL)
		{
			destroy(p->left);
			destroy(p->right);
			delete p;
			p == NULL;
		}
	}
};

int main()
{
	BinaryTree obj;
	for (int i = 0; i < 11; i++)
	{
		obj.insert(i);
		
	}
	cout << "\n\n";
	
	obj.preOrderTraversal();
	cout << endl;
	obj.inOrderTraversal();
	cout << endl;
	obj.postOrderTraversal();
	cout << endl;
	

}
