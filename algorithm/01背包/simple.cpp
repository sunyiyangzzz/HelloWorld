#include <iostream>
#include <vector>
using namespace std;
int max(const int a, const int b)
{
	return a >= b ? a : b;
}
void find(vector<vector<int>>& ditui, int i, int j)
{
}

void package(vector<int>& weight, vector<int> value, int n, int w)
{
	vector<int> hang(w + 1, 0);
	vector<vector<int>> ditui(n + 1, hang);
	int result = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (j >= weight[i - 1])
				ditui[i][j] = max(ditui[i - 1][j], ditui[i - 1][j - weight[i - 1]] + value[i - 1]);
			else
				ditui[i][j] = ditui[i - 1][j];
			result = result > ditui[i][j] ? result : ditui[i][j];
		}
	}
	cout << "µÝÍÆ¾ØÕó" << endl;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			cout << ditui[i][j] << " ";
		}
		cout << endl;
	}
	cout << result;

}
int main()
{
	vector<int> weight;
	vector<int> value;
	weight.reserve(20);
	value.reserve(20);
	int n = 0;
	int w = 0;
	cin >> n;  //number 
	cin >> w;  //sum
	int now;
	cout << "weight:" << endl;
	for (int i = 0; i < n; i++)
	{	
		cin >> now;
		weight.push_back(now);
	}
	cout << endl << "value:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> now;
		value.push_back(now);
	}
	package(weight, value, n, w);

}