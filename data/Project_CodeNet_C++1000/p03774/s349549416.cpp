#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ab(n);
    vector<vector<int>> cd(m);
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        ab[i].push_back(a);
        ab[i].push_back(b);
    }
    rep(i, m)
    {
        int c, d;
        cin >> c >> d;
        cd[i].push_back(c);
        cd[i].push_back(d);
    }
    rep(i, n)
    {
        int min_distance = 1000000000;
        int min_j;
        rep(j, m)
        {
            if (chmin(min_distance, abs(ab[i][0] - cd[j][0]) + abs(ab[i][1] - cd[j][1])))
            {
                min_j = j;
            }
        }
        cout << min_j + 1 << endl;
    }

    return 0;
}