#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    cout << ((s[0] == s[2]) ? "Yes" : "No") << endl;
    return 0;
}