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

int n;

int a[N_MAX];

ll sum;

ll k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        sum += a[i];
    k = sum / (1LL * n * (n + 1) / 2);
    if(k * (1LL * n * (n + 1) / 2) != sum)
    {
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        int j = i - 1;
        if(j == 0)
            j = n;
        ll u = k - (a[i] - a[j]);
        if(u < 0 || u % n != 0)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
