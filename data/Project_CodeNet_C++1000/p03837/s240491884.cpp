#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,M;
ll d[101][101]={};
ll a[1001],b[1001],c[1001];
set<P> st;
int main(){
    cin>>N>>M;
    for(ll i=0;i<N;i++) for(ll j=0;j<N;j++){
        if(i==j)continue;
        d[i][j]=INF;
    }
    for(ll i=0;i<M;i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;
        b[i]--;
        d[a[i]][b[i]]=c[i];
        d[b[i]][a[i]]=c[i];
    }
    for(ll k=0;k<N;k++)for(ll i=0;i<N;i++)for(ll j=0;j<N;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    ll ans=0;
    for(ll i=0;i<M;i++){
        if(d[a[i]][b[i]]<c[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}