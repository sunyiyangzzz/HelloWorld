#include <vector>
#include <string>
#include <iostream>
using namespace std;
void getnextarray(vector<int> &next, string &s2)
{
	next[0] = -1;
	for(int i = 1; i < s2.size(); i++)
	{
		int j = next[i - 1];
		while(s2[i] != s2[j + 1] && j >= 0)
			j = next[j];
		if(s2[i] == s2[j + 1] )
			next[i] = j + 1;
		else
			next[i] = -1;
	}
}
int main()
{
	string s1;
	getline(cin, s1);
	string s2;
	getline(cin, s2);
	vector<int> next(s2.size());
	getnextarray(next, s2);
	int i = 0;
	int j = 0;
	while (i < s1.size())
	{
		if(s1[i] == s2[j])
		{
			i++;
			j++;
			if(j ==s2.size() - 1)
			{
				cout << i - j;
				break;
			}
		}
		else
		{
			if(j == 0)
				i++;
			else
				j = next[j - 1] +1;

		}
	}
	system("pause");

}