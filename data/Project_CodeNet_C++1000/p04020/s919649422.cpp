#include <bits/stdc++.h>
using namespace std;

#define fast_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define show(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("-ffloat-store")
#define modulo 998244353

clock_t time_p = clock();
void time()
{
    time_p = clock() - time_p;
    cerr << "Time Taken : " << (double)(time_p) / CLOCKS_PER_SEC << '\n';
}

int main()
{
    fast_IO
    ll n, mx = 0; cin >> n;
    vector<ll> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] && a[i-1])
        {
            mx++;
            a[i]--;
        }
        mx += a[i] / 2;
        a[i] = a[i] % 2;
    }
    cout << mx << '\n';
    //time();
    return 0;
}