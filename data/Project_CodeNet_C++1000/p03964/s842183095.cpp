#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n;cin>>n;
    vector<P> vote(n),ans(n);
    rep(i,n){
        cin>>vote[i].first>>vote[i].second;
    }

    ans[0]=vote[0];
    rep(i,n-1){
        if(ans[i].first<=vote[i+1].first && ans[i].second<=vote[i+1].second){
            ans[i+1]=vote[i+1];
        }else{
            ll mul=max((ans[i].first+vote[i+1].first-1)/vote[i+1].first,(ans[i].second+vote[i+1].second-1)/vote[i+1].second);
            ans[i+1].first=mul*vote[i+1].first;
            ans[i+1].second=mul*vote[i+1].second;
        }
    }

    cout<<ans[n-1].first+ans[n-1].second<<endl;
    return 0;
}