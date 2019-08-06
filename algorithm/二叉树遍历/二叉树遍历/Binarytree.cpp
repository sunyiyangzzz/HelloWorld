#include "Binarytree.h"
void Binarytree::houxu() //���Ҹ�
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
		if (p->right == nullptr || p->right == last) //���ʸ�����������������Ϊ�ջ��ϴ��ѱ�����
		{
			cout << p->val << " ";
			last = p;
		}
		else  //������δ���ʣ��������������������
		{
			a.push(p);//���ܷ��ʸ���㣬�ƻ�ջ��
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
void Binarytree::xianxu() //������
{
	cout << endl;
	stack<node*> a;
	node* p;
	p = this->root;   //pָ����ڵ�
	while (!a.empty() || p)
	{
		while (p != nullptr) //����������ջ
		{
			cout << p->val << " ";   //ֱ�ӷ��ʸ����
			a.push(p);
			p = p->left;
		}
		p = a.top(); //��ջ�����������ѱ����ʣ��ж�������
		a.pop();
		p = p->right;
	}
}
void Binarytree::zhongxu()//�����
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
		cout << p->val <<" ";//��ջ����������������������ѱ����ʣ����ʸ����
		p = p->right;        //�������������
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
