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

int dpinc, dpdec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dpinc = dpdec = 1;
    for(int i = 2; i <= n; i++)
    {
        int dpinc1 = dpdec + 1, dpdec1 = dpinc + 1;
        dpinc1 = min(dpinc1, dpinc + (a[i - 1] > a[i]));
        dpdec1 = min(dpdec1, dpdec + (a[i - 1] < a[i]));
        dpinc = dpinc1;
        dpdec = dpdec1;
    }
    cout << min(dpinc, dpdec) << "\n";
    return 0;
}
