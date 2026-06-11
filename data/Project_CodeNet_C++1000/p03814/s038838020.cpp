#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    while (s.back() != 'Z') s.pop_back();
    reverse(s.begin(), s.end());
    while (s.back() != 'A') s.pop_back();
    cout << s.size();
}
