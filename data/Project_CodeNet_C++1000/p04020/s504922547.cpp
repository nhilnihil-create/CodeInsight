#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);

const int MAX=200010;

ll fac[MAX], finv[MAX], inv[MAX];

void cmbInit() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}


ll cmb(int n, int k){
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<int> cnt(n);
    rep(i,n) cin >> cnt[i];
    ll b=0,ans=0;
    rep(i,n) {
        ans+=(cnt[i]+b)/2;
        if (cnt[i]==0 || (cnt[i]+b)%2==0) b=0;
        else b=1;
    }
    cout << ans << endl;
    
    return 0;
}
