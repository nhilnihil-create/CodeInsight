#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
static const int mod = 1e9+7;
ll mpow(ll a, ll n){
    ll res = 1;
    while (n > 0){
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n, ans = 0; sc(n);
    vector<int> a(n);
    rep(i, 0, n) sc(a[i]);
    map<int, int> mp;
    rep(i, 0, n) ++mp[a[i]];
    for (const auto &x: mp){
        if (x.second == 2) ans++;
        else if (x.first==0 && x.second==1) continue;
        else{
            ans = -1;
            break;
        }
    }
    if (ans < 0) cout << 0 << endl;
    else cout << mpow(2, ans) << endl;
    return 0;
}