//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n,m; cin>>n>>m;
    vector<ll>x(m);
    vector<ll>y(m);
    rep(i,m)cin>>x[i]>>y[i];
    Graph G(n);
    rep(i,n)G[i].push_back(1);
    vector<bool>ans(n,false);
    ans[0]=true;
    rep(i,m){
        if(ans[x[i]-1]==true){
            if(G[x[i]-1].size()<=1)ans[x[i]-1]=false;
                G[y[i]-1].push_back(1);
                ans[y[i]-1]=true;
                G[x[i]-1].pop_back();
        }
        else{
            G[y[i]-1].push_back(1);
            G[x[i]-1].pop_back();
        }
    }
    ll sum=0;
    rep(i,n){
        if(ans[i])sum++;
    }
    cout<<sum<<endl;
}

















































