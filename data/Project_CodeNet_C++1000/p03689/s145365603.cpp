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
ll MOD=1e9+7;
#define INF 2*1e9
#define N 200000
using namespace std;
main(){
    ll H,W,h,w;
    cin>>H>>W>>h>>w;
    if(H%h==0&&W%w==0) {cout<<"No";return 0;}
    cout<<"Yes"<<endl;
    int a=((H/h)*(W/w)/(H%h*W+W%w*H-(H%h)*(W%w))+1);
    rep2(i,1,H){
        rep2(j,1,W){
            if(i%h==0&&j%w==0){
                cout<<(-a*h*w+a-1)<<" ";
            }
            else{
                cout<<a<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}