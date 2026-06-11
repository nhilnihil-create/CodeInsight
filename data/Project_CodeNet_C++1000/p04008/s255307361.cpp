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
#include<unordered_set>
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


vector<vector<ll>> edge;
ll n,k;
ll ans=0;

ll dfs(ll w,ll p){
    ll h=1;
    for(auto &I:edge[w]){
        if(I!=p){h=max(h,dfs(I,w)+1);}
    }
    if(h==k && p!=0){ans++; return 0;}
    return h;
}


int main(){
    cin>>n>>k;
    vector<ll> a(n);
    for(auto &I:a){cin>>I; I--;}
    if(a[0]!=0){ans++; a[0]=0;}
    edge.resize(n);
    for(int i=1;i<n;i++){
        edge[a[i]].push_back(i);
    }
    dfs(0,0);
    cout<<ans<<endl;
    
    
    
    return 0;
}
