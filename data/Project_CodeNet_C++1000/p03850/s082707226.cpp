#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
int MOD=1e9+7;
#define INF 2*1e9
#define N 310000 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    int a[110000];
    cin>>a[0];
    rep2(i,1,n-1){
        char c;cin>>c;
        cin>>a[i];
        if(c=='-')a[i]*=-1;
    }
    ll sum=0,pos=0;
    vector<ll> v;
    while(pos<n){
        while(a[pos]>0&&pos<n){
            sum+=a[pos];
            pos++;
        }
        v.pb(sum);
        if(pos<n) v.pb(a[pos]);
        sum=0;pos++;
    }
    ll m=1e18,temp=0;
    pos=1;
    while(pos*2<=v.size()){
        temp-=v[pos*2-1];
        m=min(m,temp+v[pos*2]);
        pos++;
    }
    rep(i,n){
        sum+=abs(a[i]);
    }
    ll M=0;
    rep(i,v.size()){
        if(i%2) M-=v[i]; 
    }
    m=min(M,m);
    cout<<sum-2*m;
    return 0;
}

