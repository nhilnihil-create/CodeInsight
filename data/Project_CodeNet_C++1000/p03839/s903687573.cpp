#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
    ll n,k,ans,sum=0,ksum=0;cin>>n>>k;
    vector<ll> v(n);
    rep(i,n){
        cin>>v[i];
        if(k<=i && v[i]>0)sum+=v[i];
        else if(i<k)ksum+=v[i];
    }
    ans=sum+max(0ll,ksum);
    //cout<<sum<<":"<<ksum<<endl;

    repi(i,k,n){
        if(v[i]>0){
            sum-=v[i];
        }
        ksum+=v[i];

        if(v[i-k]>0)sum+=v[i-k];
        ksum-=v[i-k];

        ll res=sum+max(0ll,ksum);
        ans=max(ans,res);

        //cout<<sum<<":"<<ksum<<endl;
    }

    cout<<ans<<endl;
}



