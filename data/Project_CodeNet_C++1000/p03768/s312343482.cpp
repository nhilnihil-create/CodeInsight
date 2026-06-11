#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;




vector<ll> color;
vector<ll> used;
vector<vector<ll>> edge;


void dfs(ll where,ll dist,ll clr){
    if(used[where]==-1){
        color[where]=clr;
    }
    used[where]=dist;
    if(dist==0){return;}
    for(auto &I:edge[where]){
        if(used[I]>=dist-1){continue;}
        dfs(I,dist-1,clr);
    }
}


int main(){
    ll n,m;
    cin>>n>>m;
    color.resize(n,0);
    used.resize(n,-1);
    edge.resize(n);
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ll q;
    cin>>q;
    vector<pair<pll,ll>> V(q);
    for(int t=0;t<q;t++){
        cin>>V[t].F.F>>V[t].F.S>>V[t].S;
        V[t].F.F--;
    }
    reverse(V.begin(),V.end());
    for(int i=0;i<q;i++){
        if(used[V[i].F.F]>=V[i].F.S){continue;}
        dfs(V[i].F.F,V[i].F.S,V[i].S);
    }
    for(int i=0;i<n;i++){
        cout<<color[i]<<endl;
    }
    
    
    
    
    
    
    
    return 0;
}
