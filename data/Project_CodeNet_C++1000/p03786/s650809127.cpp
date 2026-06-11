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

ll pref[N_MAX];

bool suff[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    int pos = n - 1;
    while(pos > 0 && pref[pos] * 2 >= a[pos + 1])
        pos--;
    cout << n - pos << "\n";
    return 0;
}
