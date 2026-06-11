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
    string s, t;
    int n;
    cin >> n;
    cin >> s >> t;
    for (int i = n; i >= 0; i--)
    {
        //        cout << "a:" << s.substr(n - i, i) << " " << t.substr(0, i) << endl;
        if (s.substr(n - i, i) == t.substr(0, i))
        {
            string aaaaa= s +t.substr(i);
            cout << aaaaa.length() << endl;
            break;
        }
    }
    return 0;
}