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
    std::ifstream in("./sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int cost = INF;

    for (int i = -100; i <= 100; i++)
    {
        int costtmp = 0;
        for (int j = 0; j < n; j++)
        {
            costtmp += pow(a[j] - i, 2);
        }

        cost = min(cost, costtmp);
    }

    cout << cost << endl;
}

signed main()
{
    solve();
    return 0;
}
