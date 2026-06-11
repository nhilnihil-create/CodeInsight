#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_A = 2e5 + 24;
const int INF = 1e9 + 7;
int last[MAX_A];
pair <int, pair <int, int> > dp[MAX_A];
string s;
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int sz = s.size();
    for(int i = 0; i < sz; ++ i)   dp[i].first = INF;
    for(int i = 0; i < 26; ++ i)   last[i] = sz + 2;
    for(int i = sz; i >= 0; -- i)
    {
        for(int j = 0; j < 26; ++ j)
        {
            if(last[j] == sz + 2)
            {
                dp[i].first = 0;
                dp[i].second.first = sz + 2;
                dp[i].second.second = j;
                break;
            }
            if(dp[i].first > dp[last[j] + 1].first)
            {
                dp[i].first = dp[last[j] + 1].first;
                dp[i].second.first = last[j] + 1;
                dp[i].second.second = j;
            }
        }
        ++ dp[i].first;
        if(i - 1 >= 0)   last[s[i - 1] - 'a'] = i - 1;
    }
    for(int i = 0; i <= sz; i = dp[i].second.first)
    {
        char c = dp[i].second.second + 'a';
        cout << c;
    }
    cout << "\n";
	return 0;
}
