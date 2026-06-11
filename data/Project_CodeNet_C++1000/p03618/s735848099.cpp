/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 200002;

int n;

string s;

int cnt[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    ll ans = 1LL * n * (n - 1) / 2 + 1;
    for(int i = 1; i <= n; i++)
        cnt[s[i] - 'a']++;
    for(int i = 0; i < 26; i++)
        ans -= 1LL * cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << "\n";
    return 0;
}
