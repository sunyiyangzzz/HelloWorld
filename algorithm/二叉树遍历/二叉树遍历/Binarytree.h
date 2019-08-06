#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;
struct node
{
	node* left;
	node* right;
	int val;
};
class Binarytree
{
public:
	int nodenumber;
	node* root;
	Binarytree(vector<int>& data);
	void buildtree(int& i, queue<node*> &now, vector<int>& data);
	void houxu();
	void zhongxu();
	void xianxu();
};

