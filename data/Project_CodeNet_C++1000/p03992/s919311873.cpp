#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    string s;
    cin >> s;
    string ans = s.substr(0, 4) + ' ' + s.substr(4, 8);
    cout << ans << endl;
}