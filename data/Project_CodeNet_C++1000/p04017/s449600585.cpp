#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,l,q;
ll x[100010];
ll par[100010][20];

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    cin>>l>>q;
    par[n-1][0] = -1;
    for(int i=0;i<n-1;i++){
        par[i][0] = upper_bound(x,x+n,x[i]+l) - x;
        par[i][0]--;
        //cerr << x[i] << " a " << x[par[i][0]] <<"\n";
    }
    for(int j=1;j<20;j++){
        for(int i=0;i<n;i++){
            if(par[i][j-1]==-1){
                par[i][j]=-1;
                continue;
            }
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        if(a>b)swap(a,b);
        ll ans = 0;
        ll now = 19;
        while(a < b){
            while(now >0 && (par[a][now]==-1 || par[a][now]>b)){
                now--;
            }
            ans += (1LL<<now);
            a = par[a][now];
        }
        cout << ans << "\n";
    }
}