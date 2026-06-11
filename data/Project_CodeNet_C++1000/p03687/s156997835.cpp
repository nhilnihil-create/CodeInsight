/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    int ans = INT_MAX;
    for(int c = 0; c < 26; c++)
    {
        int last = 0;
        int mx = 0;
        for(int i = 1; i <= n; i++)
            if(s[i] == char('a' + c))
            {
                mx = max(mx, i - last - 1);
                last = i;
            }
        mx = max(mx, n - last);
        ans = min(ans, mx);
    }
    cout << ans << "\n";
    return 0;
}
