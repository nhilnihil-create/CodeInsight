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
typedef long double D;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


vector<vector<ll>> edge;

ll dfs(ll w,ll p){
    ll ret=0;
    for(auto &I:edge[w]){
        if(I!=p){ret^=dfs(I,w)+1;}
    }
    return ret;
}



int main(){
    ll n;
    cin>>n;
    edge.resize(n);
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    cout<<(dfs(0,-1)==0?"Bob":"Alice")<<endl;
    
    
    return 0;
}
