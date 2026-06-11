#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;
const int INF = 1e18;

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    map<int, int> mp;
    rep(i, n) mp[A[i]]++;

    int tmp1 = 0;
    for (auto a : mp)
    {
        if (a.second >= 2)
        {
            tmp1 = max(tmp1, a.first);
        }
    }
    mp[tmp1] -= 2;

    int tmp2 = 0;
    for (auto a : mp)
    {
        if (a.second >= 2)
        {
            tmp2 = max(tmp2, a.first);
        }
    }
    mp[tmp2] -= 2;

    cout << tmp1 * tmp2 << endl;

}

signed main()
{
    solve();
    return 0;
}
