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

ll mod = 1000000007;

signed main()
{
    int n, m;
    cin >> n >> m;
    vi num_of_balls(n, 1);
    vi is_red_possible(n, 0);
    is_red_possible[0] = 1;
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        if (is_red_possible[x - 1])
        {
            is_red_possible[y - 1] = 1;
            num_of_balls[x - 1]--;
            num_of_balls[y - 1]++;
            if (num_of_balls[x - 1] == 0)
            {
                is_red_possible[x - 1] = 0;
            }
        }
        else
        {
            num_of_balls[x - 1]--;
            num_of_balls[y - 1]++;
        }
    }
    int ans = 0;
    rep(i, n)
    {
        if(is_red_possible[i]==1){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}