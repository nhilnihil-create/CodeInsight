#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
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
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n),b(n);
    ll ans=0;
    rep(i,n){
        ll c;cin>>c;
        if(c>0)ans+=c;
        if(i!=0){
            a[i]=a[i-1]+c;
            if(c>0)b[i]=b[i-1]+c;
            else b[i]=b[i-1];
        }else{
            a[i]=c;
            if(c>0)b[i]=c;
        }
    }
    //rep(i,n)cout<<b[i]<<endl;
    ll ma=ans-b[k-1]+a[k-1];
    ma=max(ma,ans-b[k-1]);
    REP(i,k,n){
        ma=max(ans-(b[i]-b[i-k])+a[i]-a[i-k],ma);
        ma=max(ma,ans-(b[i]-b[i-k]));
        //cout<<i<<' '<<a[i]-a[k]<<' '<<b[i]-b[k]<<endl;
    }
    cout<<ma<<endl;
}