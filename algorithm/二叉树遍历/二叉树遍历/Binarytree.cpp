#include "Binarytree.h"
void Binarytree::houxu() //左右根
{
	cout << endl;
	stack<node*> a;
	node* p = this->root;
	node* last = nullptr;
	while (p)
	{
		a.push(p);
		p = p->left;
	}
	while (!a.empty())
	{
		p = a.top();
		a.pop();
		if (p->right == nullptr || p->right == last) //访问根结点的条件：右子树为空或上次已被访问
		{
			cout << p->val << " ";
			last = p;
		}
		else  //右子树未访问，则访问右子树的左子树
		{
			a.push(p);//不能访问根结点，推回栈中
			p = p->right;
			while (p)
			{
				a.push(p);
				p = p->left;
			}
		}
	}
	//cout << endl;
	//stack<node*> a;
	//node* p;
 //   node* last = nullptr;
	//p = this->root;
	//while (p)
	//{
	//	a.push(p);
	//	p = p->left;
	//}
	//while (!a.empty())
	//{
	//	p = a.top();
	//	a.pop();
	//	if (p->right == nullptr || p->right == last)
	//	{
	//		cout << p->val << " ";
	//		last = p;
	//	}
	//	else
	//	{
	//		a.push(p);
	//		p = p->right;
	//		while (p)
	//		{
	//			a.push(p);
	//			p = p->left;
	//		}
	//	}
	//
	//}

}
void Binarytree::xianxu() //根左右
{
	cout << endl;
	stack<node*> a;
	node* p;
	p = this->root;   //p指向根节点
	while (!a.empty() || p)
	{
		while (p != nullptr) //左子树推入栈
		{
			cout << p->val << " ";   //直接访问根结点
			a.push(p);
			p = p->left;
		}
		p = a.top(); //出栈结点的左子树已被访问，判断右子树
		a.pop();
		p = p->right;
	}
}
void Binarytree::zhongxu()//左根右
{
	stack<node*> a;
	node* p;
	p = this->root;
	while (!a.empty() || p)
	{
		while (p != nullptr)
		{
			a.push(p);
			p = p->left;
		}
		p = a.top();
		a.pop();
		cout << p->val <<" ";//出栈结点无左子树，或左子树已被访问，访问根结点
		p = p->right;        //最后搜索右子树
	}
}
void Binarytree::buildtree(int& i,queue<node*> &now, vector<int>& data)
{
	while (!now.empty())
	{
		node* a = now.front();
		if (i + 1 <= data.size())
		{
			node* left = new node;
			a->left = left;
			left->left = nullptr;
			left->right = nullptr;
			left->val = data[i++];
			now.push(left);
		}
		else
			return;
		if (i + 1 <= data.size())
		{
			node* left = new node;
			a->right = left;
			left->left = nullptr;
			left->right = nullptr;
			left->val = data[i++];
			now.push(left);
		}
		else
			return;
		now.pop();
	}
	

}
Binarytree::Binarytree(vector<int>& data)
{
	if (data.size() == 0)
	{
		root = nullptr;
		return;
	}
	int i = 1;
	root = new node;
	root->val = data[0];
	root->left = nullptr;
	root->right = nullptr;
	queue<node*> now;
	now.push(root);
	buildtree(i, now, data);
}
int main()
{
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	Binarytree t = Binarytree(data);
	t.zhongxu();
	t.xianxu();
	t.houxu();
}
