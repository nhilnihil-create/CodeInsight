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

int n, m;

int a[N_MAX], b[N_MAX];

int cnt[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    for(int i = 1; i <= n; i++)
        if(cnt[i] & 1)
        {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
