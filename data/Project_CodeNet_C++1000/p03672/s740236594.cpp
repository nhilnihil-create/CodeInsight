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
void chmax(t &a, u b)
{
    if (a < b)
        a = b;
}
template <class t, class u>
void chmin(t &a, u b)
{
    if (b < a)
        a = b;
}

bool is_guumojiretu(string s)
{
    int l = s.size();
    for (size_t i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l / 2 + i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s;
    cin >> s;
    for (size_t i = s.size() - 2; i >= 0; i -= 2)
    {
        if (is_guumojiretu(s.substr(0, i)))
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}