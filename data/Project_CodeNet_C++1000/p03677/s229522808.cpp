#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e5+10;
const ll oo = 1e18;

int n,m,a[maxn];
ll f[maxn],X[maxn];

int main() {
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        int l = a[i], r = a[i+1];
        if (l<r) {
            f[0]+=r-l;
            f[l+1]-=r-l;
            f[r+1]+=r-l;

            f[l+1]+=r+1;
            f[r+1]-=r+1;

            X[l+1]--;
            X[r+1]++;
        } else {
            f[r+1]+=m-l+r;
            f[l+1]-=m-l+r;

            f[0]+=r+1;
            f[r+1]-=r+1;
            f[l+1]+=m+r+1;

            X[0]--;
            X[r+1]++;
            X[l+1]--;
        }
    }
    ll ans = oo;
    for (int i=1;i<=m;i++) {
        f[i]+=f[i-1];
        X[i]+=X[i-1];
        ans = min(ans,f[i]+1ll*i*X[i]);
    }
    cout<<ans<<endl;
}
