/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 52;

int n, p;

int a[N_MAX];

int cnt[2];

ll p2[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cnt[(a[i] & 1)]++;
    p2[0] = 1;
    for(int i = 1; i <= n; i++)
        p2[i] = p2[i - 1] * 2;
    if(cnt[1] == 0)
    {
        if(p == 0)
            cout << p2[cnt[0]] << "\n";
        else
            cout << "0\n";
        return 0;
    }
    cout << 1LL * p2[cnt[0]] * p2[cnt[1] - 1] << "\n";
    return 0;
}
