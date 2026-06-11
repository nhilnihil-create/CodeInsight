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
#include<complex>
#include<tuple>
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

ll n;
vector<ll> a;
vector<vector<ll>> edge;

ll dfs(ll v,ll p){
    if(p!=-1 && edge[v].size()==1){return a[v];}
    ll sum=0;
    ll MX=0;
    ll can=0;
    for(auto &i:edge[v]){
        if(i==p){continue;}
        ll ret=dfs(i,v);
        if(ret==-1){return -1;}
        sum+=ret;
        MX=max(MX,ret);
    }
    if(MX*2<=sum){
        can=sum/2;
    }
    else{
        can=sum-MX;
    }
    if(sum<a[v] || sum-a[v]>can){return -1;}
    return sum-(sum-a[v])*2;
}


int main(){
    cin>>n;
    a.resize(n);
    edge.resize(n);
    for(auto &i:a){cin>>i;}
    for(int i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    if(edge[0].size()==1){
        cout<<(dfs(0,-1)==a[0]?"YES":"NO")<<endl;
    }
    else{
        cout<<(dfs(0,-1)==0?"YES":"NO")<<endl;
    }
    
    
    return 0;
}
