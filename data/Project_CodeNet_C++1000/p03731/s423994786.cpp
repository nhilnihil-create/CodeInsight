#include <bits/stdc++.h>
using namespace std;

#define   ll     long long int

const int N = 200005;
ll ara[N];

int main( )
{
    ll s = 0, i, j, k, t, n;
    cin >> n >> t;
    for (i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    s += t;
    for (i = 2; i <= n; i++) {
        if (ara[i - 1] + t < ara[i]) {
            s += t;
        }
        else {
            s += (ara[i] - ara[i - 1]);
        }
    }
    cout << s << '\n';
    return 0;
}