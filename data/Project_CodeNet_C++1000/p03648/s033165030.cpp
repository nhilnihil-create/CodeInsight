#include <stdio.h>
#include <bits/stdc++.h>
     
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
 
using namespace std;
 
const int N = 200000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-6;
const double pi = atan2(0, -1);
const int ABC = 26;
 
int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    //ll TL = 1.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    ll k;
    cin >> k;
    int n = 50;
    ll a[n];
    rep(i, 0, n)
        a[i] = i + k / n;
    k %= n;
    while (k--)
    {
        int p = 0;
        rep(i, 0, n)
            if (a[i] < a[p])
                p = i;
        rep(i, 0, n)
            if (i == p)
                a[i] += n;
            else
                a[i]--;
    }
    cout << n << "\n";
    rep(i, 0, n)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}