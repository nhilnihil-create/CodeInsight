#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    rep(i, 4)
    {
        cout << s[i];
    }
    cout << " ";
    rep(i, s.length() - 4)
    {
        cout << s[i + 4];
    }
    cout << endl;
    return 0;
}
