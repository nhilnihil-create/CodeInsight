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

    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    rep(i, n) cin >> a[i] >> b[i];

    map<int, int> mp;
    rep(i, n) mp[a[i]] += b[i];

    vector<pair<int, int>> vec;
    for (auto now : mp)
        vec.push_back(make_pair(now.first, now.second));

    sort(ALL(vec));

    int tmp = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (tmp <= k && k <= tmp + vec[i].second)
        {
            cout << vec[i].first << endl;
            break;
        }
        else
        {
            tmp += vec[i].second;
        }
    }
}

signed main()
{
    solve();
    return 0;
}
