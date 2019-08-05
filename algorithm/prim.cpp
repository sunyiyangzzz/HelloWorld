#include <vector>
#include <queue>
using namespace std;
class xianduan
{
public:
    int strat;
    int end;
    int value;
    bool operator<(xianduan& a, xianduan& b)
    {
        return a.value < b.value;
    }
    bool operator>(xianduan& a, xianduan& b)
    {
        return a.value > b.value;
    }
    bool operator==(xianduan& a, xianduan& b)
    {
        return a.value == b.value;
    }
}
vector<vector<int>> Map;
vector<int> cixu;
int main()
{
    int k;
    cin >> k;
    k = k - 1;
    vector<int> visit(Map.size(), 0);
    visit[k] = 1;
    priority_queue<xianduan, vector<xianduan>, greater<xianduan>> now;
    for(int i = 0; i < visit.size(); i++)
    {
        if(i != k && Map[i][k] != MAX_INT)
        {
            xianduan a;
            a.start = k;
            a.end = i;
            a.value = Map[i][k];
            now.push(a);
        }
    }
    cixu.push_back(k);
    while( !now.empty() && cixu.size() < visit.size())
    {
        xianduan themin = now.top();
        if(visit[themin.end] == 0)
        {
            visit[themin.end] = 1;
            cixu.push_back(themin.end);
            for(int i = 0; i < visit.size(); i++)
            {
                  if(visit[i] != 1 && Map[themin.end][i] != MAX_INT)
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
    
}