//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    cout<<fixed<<setprecision(15);
    ll n,a,b,cnt=0; cin>>n>>a>>b;
    ld ans=0.0;
    vector<ll> v(n,0);
    map<ll,ll> M,m;
    rep(i,n){
        cin>>v[i];
        if(M.count(v[i])) M[v[i]]++;
        else M[v[i]]=1;
    }
    sort(al(v)); reverse(al(v));
    rep(i,a){
        ans+=v[i];
        if(m.count(v[i])) m[v[i]]++;
        else m[v[i]]=1;
    }
    ans/=a;
    cout<<ans<<endl;
    if(m.size()==1){
        ll k=min(b,M[v[0]]),ad=1;
        for(ll i=a;i<=k;i++){
            ad=1;
            for(ll j=1;j<=i;j++){
                ad*=M[v[0]]-j+1;
                ad/=j;
            }
            cnt+=ad;
        }
    }
    else{
        cnt=1;
        for(ll i=1;i<=m[v[a-1]];i++){
            cnt*=M[v[a-1]]-i+1;
            cnt/=i;
        }
    }
    cout<<cnt<<endl;
}