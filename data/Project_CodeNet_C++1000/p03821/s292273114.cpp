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
ll b[100100];

int main()
{
    ll n, i, ans = 0;

    cin >> n;

    for(i = 0; i < n; i++)cin >> a[i] >> b[i];

    for(i = n-1; i >= 0; i--){
        ans += b[i]-(((a[i]+ans)%b[i] == 0LL)?b[i]:(a[i]+ans)%b[i]);
    }

    cout << ans << endl;
}
