#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int INF = 1e9;
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
void solve()
{
    string s;
    cin >> s;
    map<char, deque<int>> mp;
    int cta = 0;
    int x = s.length();
    for (auto i : s)
        mp[i].push_back(++cta);
    int res = INF;
    for (auto i : mp)
    {
        int tmp = 0;
        int len = i.second.size();
        for (int j = 0; j <= len; ++j)
        {
            if (j == 0)
                tmp = max(tmp, i.second[j] - 1);
            else if (j == len)
                tmp = max(tmp, abs(x - i.second[j - 1]));
            else
                tmp = max(tmp, abs(i.second[j] - i.second[j - 1]) - 1);
        }
        res = min(res, tmp);
    }
    cout << res << endl;
}
int main(void)
{
    solve();
}