#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(n,v) cout<<#v<<":";for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n;
vector<vector<int>> g;
int dfs(int v){
    if(g[v].empty()) return 1;
    vector<int> vec;
    for(auto x:g[v]){
        vec.push_back(dfs(x));
    }
    sort(ALL(vec),greater<int>());
    int ret=0;
    for(int i=0;i<vec.size();i++){
        ret=max(ret,i+1+vec[i]);
    }
    return ret;
}

int main(){
    cin>>n;
    g.resize(n);
    for(int i=1;i<n;i++){
        int t;cin>>t;t--;
        g[t].push_back(i);
    }
    cout<<(dfs(0)-1)<<endl;
    return 0;
}