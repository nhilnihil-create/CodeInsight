#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define err(A) cout << #A << " = " << (A) << endl
using namespace std;

const int N=1e5+100,M=20;

ll a[N];
ll par[N][M];
int32_t main(){
    sync;
    ll n,l;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> l;
    for (int i=0;i<n;i++){
        ll z=lower_bound(a,a+n,a[i]+l+1)-a-1;
        par[i][0]=z;
     //   cout << i << " " << par[i][0] << endl;
    }
    for (int i=1;i<M;i++){
        for (int j=0;j<n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
         //   cout << j << " " << i << " " << par[j][i] << endl;
        }
    }
    ll q;
    cin >> q;
    for (int i=0;i<q;i++){
        ll u,v;
        cin >> u >> v;
        u--,v--;
        if (v<u){
            swap(u,v);
        }
        ll t=u;
        ll ans=0;
        for (int j=M-1;j>-1;j--){
            if (par[t][j]<v){
                ans+=(1<<j);
                t=par[t][j];
            }
        }
        cout << ans+1 << endl;
    }


}
