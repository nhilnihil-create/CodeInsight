#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

ll modPow(ll a, ll n, ll mod)
{
    if(n == 1)return a;
    if(n % 2 == 1) return (a * modPow(a, n-1, mod)) % mod;
    ll t = modPow(a, n/2, mod);
    return (t * t) % mod;
}


int main()
{
    int n, p; cin >> n >> p;
    int cnt = 0;
    ll ans = 1;
    rep(i, n){
        int a; cin >> a;
        if(a % 2 == 0) cnt++;
    }
    for(int i = 0; i < n; i++) ans *= 2;
    if(cnt != n)ans /= 2;
    if(cnt == n && p == 1)ans = 0;
    cout << ans << endl;
    system("pause");
}
