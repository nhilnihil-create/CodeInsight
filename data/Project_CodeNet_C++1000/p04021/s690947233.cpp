#include <bits/stdc++.h>
#include <cstdio>
#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define nln cout << '\n'
#define ll long long int
#define INF (ll)1e+12
#define MAX 300100
#define mp(i, j) make_pair(i, j)
#define here cout  << "here";nln;
#define mul(a, b, mod) (((a % mod) * (b % mod)) % mod)
#define add(a, b, mod) (((a % mod) + (b % mod)) % mod)
#define inf 100000
#define M 1000000000LL

using namespace std;

ll a[100100];
set <ll> b;
set <ll> c;

int main()
{
    ll n;

    ll i, ans = 0, m;

    cin >> n;

    for(i = 0; i < n; i++)cin >> a[i];

    for(i = 0; i < n;)if(++i&1)b.insert(a[i-1]);

    sort(a, a+n);

    for(i = 0; i < n;)if(++i&1)c.insert(a[i-1]);

    for(auto it = b.begin(); it != b.end(); it++){
        if(c.count(*it) == 0)ans++;
    }
    cout << ans << endl;

}
