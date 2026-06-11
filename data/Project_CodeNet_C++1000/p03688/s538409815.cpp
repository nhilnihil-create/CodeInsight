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
    int n;
    cin >> n;
    map<int, int> m;
    rep(i, n)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    if (m.size() > 2)
    {
        cout << "No" << endl;
        return 0;
    }
    if (m.size() == 1)
    {
        int a = m.begin()->first;
        if (a == n - 1 || a <= n / 2)
        {
            cout << "Yes" << endl;
            return 0;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    else
    {
        int a = m.begin()->first;
        auto it = m.begin();
        it++;
        int b = it->first;
        if (b != a + 1)
        {
            cout << "No" << endl;
            return 0;
        }
        else
        {
            if (m[a] > a)
            {
                cout << "No" << endl;
                return 0;
            }
            else if (m[b] < (b - m[a]) * 2)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}