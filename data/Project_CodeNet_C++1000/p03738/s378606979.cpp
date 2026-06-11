#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string a, b;
    cin >> a >> b;
    int maxsize = max(a.size(), b.size());
    if (a.size() != maxsize)
    {
        int addsize = maxsize - a.size();
        rep(i, addsize)
        {
            a = '0' + a;
        }
    }
    if (b.size() != maxsize)
    {
        int addsize = maxsize - b.size();
        rep(i, addsize)
        {
            b = '0' + b;
        }
    }
    if (a > b)
        cout << "GREATER" << endl;
    else if (a < b)
        cout << "LESS" << endl;
    else
        cout << "EQUAL" << endl;
}

int main()
{
    solve();
    return 0;
}