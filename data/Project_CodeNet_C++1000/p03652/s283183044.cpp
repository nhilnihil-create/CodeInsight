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
    vector<vector<int>> A;
    rep(i, n)
    {
        vector<int> aa;
        rep(j, m)
        {
            int a;
            cin >> a;
            aa.push_back(a);
        }
        A.push_back(aa);
    }
    vector<int> num(m, 0);
    rep(i, n)
    {
        num[A[i][0] - 1]++;
    }
    int kind = m;
    int ans = 100000000;
    vector<int> l(m, 1);
    while (kind > 0)
    {
        int max_num = 0;
        int max_i = 0;
        rep(i, m)
        {
            if (num[i] > max_num)
            {
                max_num = num[i];
                max_i = i;
            }
        }
//        cout << max_i << " " << max_num << endl;
        chmin(ans, max_num);
        l[max_i] = 0;
        num.clear();
        num.resize(m, 0);
        rep(i, n)
        {
            rep(j, m)
            {
                if (l[A[i][j] - 1] == 1)
                {
                    num[A[i][j] - 1]++;
                    break;
                }
            }
        }
        kind--;
    }
    cout << ans << endl;
    return 0;
}