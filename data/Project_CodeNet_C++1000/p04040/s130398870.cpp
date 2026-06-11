#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back
const int mod = 1e9+7;

ll f1[200005], f2[200005];
ll pow2(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b%2 == 1) ans = ans*a%mod;
        a = a*a%mod;
        b/=2;
    }
    return ans;
}
ll nCr(int a, int b){
    return f1[a]*f2[b]%mod*f2[a-b]%mod;
}

int main(){
    f1[0] = f2[0] = 1;
    for(int i=1;i<=200000;i++){
        f1[i] = f1[i-1]*i%mod;
        f2[i] = pow2(f1[i], mod-2);
    }
    int h, w, a, b;
    scanf("%d%d%d%d", &h, &w, &a, &b);
    ll ans = nCr(h-1+w-1, h-1);
    for(int i=1;i<=b;i++){
        int r = h-a;
        int c = i;
        ll res = nCr(r-1+c-1, r-1)*1ll*nCr(h-(r+1)+w-c, h-(r+1))%mod;
        ans = (ans - res + mod)%mod;
    }
    printf("%lld\n", ans);
}