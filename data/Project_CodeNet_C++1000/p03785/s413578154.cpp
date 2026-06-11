/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;

int n, c, k;

int t[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c >> k;
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    sort(t + 1, t + n + 1);
    int cnt = 1;
    int first = t[1];
    int ans = 1;
    for(int i = 2; i <= n; i++)
    {
        if(first + k < t[i] || cnt >= c)
        {
            ans++;
            first = t[i];
            cnt = 0;
        }
        cnt++;
    }
    cout << ans << "\n";
    return 0;
}
