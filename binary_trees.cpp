// binary_trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stack>
#include<memory>
#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

struct Node
{
	int num; Node* left, *right;
};
class b_tree {
private:
	void invert_rec(Node* n)
	{
		Node* temp = n->left;
		n->left = n->right;
		n->right = temp;
		if (n->left) invert_rec(n->left);
		if (n->right) invert_rec(n->right);
	}
public:
	Node* root;
	b_tree(Node * n) :root(n) {}
	~b_tree()
	{
		if (!root)return;
		stack<Node*> s;
		s.push(root); Node* temp = root;
		while (!s.empty())
		{
			temp = s.top(); s.pop();
			if (temp->left) s.push(temp->left);
			if (temp->right) s.push(temp->right);
			delete temp;
		}
	}
	void invert()
	{
		invert_rec(root);
	}
	void find_all_paths()
	{
		cout << "Find_all_paths" << endl;
		stack<Node*> s; s.push(root);
		stack<string> st;
		string path; Node* temp;
		vector<string> v;
		st.push("");
		while (!s.empty())
		{
			path = st.top(); st.pop();
			temp = s.top(); s.pop();
			path += to_string(temp->num) + " ";
			if (temp->left) { s.push(temp->left); st.push(path); }
			if (temp->right) { s.push(temp->right); st.push(path); }
			if (!temp->left && !temp->right) v.push_back(path);
		}
		for (vector<string>::iterator i = v.begin(); i != v.end(); ++i)
			cout << *i << "\n";
	}
	void post_order()
	{
		cout << "post-order" << endl;
		stack<Node*> stack, order;
		stack.push(root);
		while (!stack.empty())
		{
			Node* temp = stack.top(); stack.pop();
			order.push(temp);
			if (temp->left) stack.push(temp->left);
			if (temp->right) stack.push(temp->right);
		}
		while (!order.empty())
		{
			Node* temp = order.top(); order.pop();
			cout << temp->num << " ";
		}
	}
	void in_order()
	{
		cout << "inorder trav" << endl;
		// create an empty stack
		stack<Node*> stack;

		// start from root node (set current node to root node)
		Node *curr = root;

		// if current node is null and stack is also empty, we're done
		while (!stack.empty() || curr != nullptr)
		{
			// if current node is not null, push it to the stack (defer it)
			// and move to its left child
			if (curr != nullptr)
			{
				stack.push(curr);
				curr = curr->left;
			}
			else
			{
				// else if current node is null, we pop an element from stack,
				// print it and finally set current node to its right child
				curr = stack.top();
				stack.pop();
				cout << curr->num << " ";
				curr = curr->right;
			}
		}
		cout << "\n";
	}
	void level_order()
	{
		cout << "spiral-order:" << endl;
		queue<Node*> q;
		q.push(root);
		bool direction = 1;
		while (!q.empty())
		{
			int level_size = q.size();
			for (int i = 0; i < level_size; i++)
			{
				Node* temp = q.front();	q.pop();
				cout << temp->num << " ";
				if(temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
			cout << endl;
		}
	}
};
int main()
{
	while (1) {
		Node* a = new Node(); a->num = 1;
		a->left = new Node(); a->left->num = 2;
		a->right = new Node(); a->right->num = 3;
		a->left->left = new Node(); a->left->left->num = 4;
		a->left->right = new Node(); a->left->right->num = 5;
		a->right->left = new Node(); a->right->left->num = 6;
		a->right->right = new Node(); a->right->right->num = 7;
		b_tree* b = new b_tree(a);
		b->find_all_paths();
		b->in_order();
		b->post_order();
		b->invert();
		b->level_order();
		delete(b);
	}
	return 0;
}

