#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
//Warshall_Floyd
//1-indexes
vector<vector<ll> >d(310,vector<ll>(310,inf));
void Warshall_Floyd(ll n){
    REP(k,1,n+1){
        REP(i,1,n+1){
            REP(j,1,n+1)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}
int main(){
    ll n,m,R;cin>>n>>m>>R;
    vector<ll>r(R);
    rep(i,R){
        cin>>r[i];
    }
    sort(all(r));
    rep(i,m){
        ll a,b,c;cin>>a>>b>>c;
        d[a][b]=c;
        d[b][a]=c;
    }
    Warshall_Floyd(n);
    ll ans=inf*inf;
    do{
        ll cnt=0;
        rep(i,R-1){
            cnt+=d[r[i]][r[i+1]];
        }
        ans=min(ans,cnt);
    }while(next_permutation(all(r)));
    cout<<ans<<endl;
}