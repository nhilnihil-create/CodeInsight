#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define pll         pair<long,long>
#define vi          vector<int>
#define vll         vector<ll>
#define vii         vector<pii>
#define Mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define mod        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rem(i,a,b)  for(int i=a;i>b;i--)
#define mp(a,b)     make_pair(a,b)
#define vvi(a,b,name)    vector<vector<int>> name(a,vector<int>(b,-1))



ll solve(ll h,ll w){
    ll mah=1;
    ll ans=mod;
    rep(i,mah,h){
        ll ma=i*w;
        ll meh=(h-i+1)/2;
        ll mih=(h-i-meh);
        ll maxa=max(ma,meh*w);
        ll mina=min(ma,mih*w);
        ans=min(ans,maxa-mina);
    }
    rep(i,mah,h){
        ll ma=i*w;
        ll mew=(w+1)/2;
        ll miw=(w-mew);
        ll maxa=max(ma,mew*(h-i));
        ll mina=min(ma,miw*(h-i));
        ans=min(ans,maxa-mina);
    }
    return ans;



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long t=1;
    //cin>>t;
    while(t--){
        ll h,w;cin>>h>>w;
        cout<<min(solve(h,w),solve(w,h));
    }
    return 0;
}
