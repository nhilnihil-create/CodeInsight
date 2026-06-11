#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define inside sl<=l&&r<=sr
#define outside r<sl||sr<l
#define orta ((l+r)>>1)
#define sol (node+node)
#define sag (node+node+1)
#define inf 1000000009
#define infll 1000000000000000009
#define eps 1e-9
#define ppair(x)  "(" << x.first << ", " << x.second << ") "
#define bas(x) #x << ": " << x << " "
#define prarr(x, n); {cout << #x << ": "; for(ll qsd = 0; qsd < n; qsd++) cout << x[qsd] << " "; cout << "\n";}
#define prarrv(x); {cout << #x << ": "; for(ll qsd: x) cout << qsd << " "; cout << "\n";}
#define ii pair<ll, ll>
#define mod 1000000007 // 998244353
using namespace std;
typedef long long ll;

vector<ll> arr;
ll n, a, b;

ll bul(ll x){
    ll ans = x;
    for (ll i = 0; i < n; i++){
        ll kes = arr[i] - b*x;
        kes = max(kes, 0LL);
        ans -= kes/a + (kes%a != 0);
    }
    if (ans < 0) return 0;
    return 1;
}

int main(){
//    freopen("/home/cahid/CLionProjects/main/in", "r", stdin);


    cin >> n >> a >> b;
    a = a-b;
    arr.resize(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    ll l = 1;
    ll r = 1000000000;
    while (l < r){
        ll mid = (l+r)/2;
        if (bul(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << endl;
}
