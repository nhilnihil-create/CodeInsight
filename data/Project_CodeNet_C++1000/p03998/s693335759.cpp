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

signed main()
{
    string a, b, c;
    cin >> a >> b >> c;
    int turn = 0;
    int aa = 0;
    int bb = 0;
    int cc = 0;
    while (true)
    {
        if (turn == 0)
        {
            if (aa == a.size())
            {
                cout << "A" << endl;
                return 0;
            }
            else
            {
                turn = a[aa] - 'a';
                aa++;
            }
        }
        else if (turn == 1)
        {
            if (bb == b.size())
            {
                cout << "B" << endl;
                return 0;
            }
            else
            {
                turn = b[bb] - 'a';
                bb++;
            }
        }
        else if (turn == 2)
        {
            if (cc == c.size())
            {
                cout << "C" << endl;
                return 0;
            }
            else
            {
                turn = c[cc] - 'a';
                cc++;
            }
        }
    }
    return 0;
}