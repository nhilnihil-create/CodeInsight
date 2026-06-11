#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

ll a[100000];
ll b[100000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    ll sum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        a[i] += sum;
        ll x = (b[i] - a[i] % b[i]) % b[i];
        sum += x;
    }
    cout << sum;
}
