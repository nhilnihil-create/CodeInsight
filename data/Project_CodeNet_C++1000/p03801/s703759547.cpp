#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=998244353;
#define INF (ll)1e16
#define N 310000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int a[N]={};
    ll int n;
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    pair<ll,ll> b[N]={};
    ll int pos=0; b[pos].first=0;b[pos].second=0;
    ll int ans[N]={},ruiseki[N]={};
    rep(i,n){
        if(b[pos].first<a[i]){
            pos++;b[pos].first=a[i];b[pos].second=i+1;
        }
        pair<ll,ll> p={a[i],0};
        ll int t=lower_bound(b,b+pos,p)-b;
        ans[b[t].second]+=a[i]-b[t-1].first;
        ruiseki[1]++;ruiseki[t]--;
    }
    rep2(i,1,pos){
        ruiseki[i]+=ruiseki[i-1];
        ans[b[i].second]+=ruiseki[i]*(b[i].first-b[i-1].first);
    }
    rep2(i,1,n){
        cout<<ans[i]<<endl;
    }

}
