#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto i : s)
        mp[i]++;
    if (mp['N'] > 0 && mp['S'] > 0 && mp['E'] > 0 && mp['W'] > 0)
        cout << "Yes" << endl;
    else if (mp['N'] > 0 && mp['S'] > 0 && mp['E'] == 0 && mp['W'] == 0)
        cout << "Yes" << endl;
    else if (mp['N'] == 0 && mp['S'] == 0 && mp['E'] > 0 && mp['W'] > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main(void)
{
    solve();
}