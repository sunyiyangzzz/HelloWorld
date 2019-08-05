#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class xianduan
{
public:
	int start;
	int end;
	int value;
	bool operator<(const xianduan& a) const
	{
		return this->value < a.value;
	}
	bool operator>(const xianduan& b)
	{
		return this->value > b.value;
	}
	bool operator==(xianduan& b)
	{
		return this->value == b.value;
	}
};
class compare
{
public:
	bool operator()(xianduan& a, xianduan& b)
	{
		return a > b;
	}
};
vector<int> cixu;
int main()
{
	int n;
	cin >> n; //¶¥µãÊý
	vector<int> maxx(n, INT_MAX);
	vector<vector<int>> Map(n, maxx);
	int bianshu;
	cin >> bianshu; //±ßÊý
	for (int i = 0; i < bianshu; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;  //v1<--->v2   value
		Map[start - 1][end - 1] = value;
		Map[end - 1][start - 1] = value;
	}
	int k;
	cin >> k;
	k = k - 1;
	vector<int> visit(Map.size(), 0);
	visit[k] = 1;
	priority_queue<xianduan, vector<xianduan>, compare> now;
	for (int i = 0; i < visit.size(); i++)
	{
		if (i != k && Map[i][k] != INT_MAX)
		{
			xianduan a;
			a.start = k;
			a.end = i;
			a.value = Map[i][k];
			now.push(a);
		}
	}
	cixu.push_back(k);
	while (!now.empty() && cixu.size() < visit.size())
	{
		xianduan themin = now.top();
		if (visit[themin.end] == 0)
		{
			visit[themin.end] = 1;
			cixu.push_back(themin.end);
			for (int i = 0; i < visit.size(); i++)
			{
				if (visit[i] != 1 && Map[themin.end][i] != INT_MAX)
				{
					xianduan a;
					a.start = themin.end;
					a.end = i;
					a.value = Map[themin.end][i];
					now.push(a);
				}
			}
		}
		now.pop();
	}
	cout << endl;
	for (int i = 0; i < cixu.size(); i++)
		cout << " " << cixu[i] + 1;

}