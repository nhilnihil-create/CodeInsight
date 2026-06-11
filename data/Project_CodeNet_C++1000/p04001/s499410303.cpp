#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    string S;
    cin >> S;
    vector<vector<int>> t((1 << (S.size() - 1)), vector<int>(1, 0));
    ll ans(0);
    for (int bit = 0; bit < (1 << (S.size() - 1)); ++bit)
    {
        rep(i, 0, S.size())
        {
            if (bit & (1 << i))
                t[bit].push_back(i + 1);
        }
        t[bit].push_back(S.size());
    }
    rep(i, 0, 1 << S.size() - 1)
    {
        rep(j, 1, t[i].size())
        {
            rep(x, t[i][j - 1], t[i][j])
                ans += (S[x] - '0') * powl(10, t[i][j] - x - 1);
        }
    }
    cout << ans << endl;
}
int main()
{
    func();
}