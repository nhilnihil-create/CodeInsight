#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 4e4+5;
int add(ll a, ll b) {return (a + b + mod) % mod;}
int mul(ll a, ll b) {return (a * b) % mod;}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[m], suma = 0, sumb = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], suma = add(suma, a[i]);
    for (int i = 0; i < m; i++)
        cin >> b[i], sumb = add(sumb, b[i]);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        suma = add(suma, -a[i]);
        x = add(x, suma);
        x = add(x, -mul(a[i], n - i - 1));
    }
    for (int i = 0; i < m; i++)
    {
        sumb = add(sumb, -b[i]);
        y = add(y, sumb);
        y = add(y, -mul(b[i], m - i - 1));
    }
    cout << mul(x, y);
    return 0;
}
