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

vector<ll> a;

vector<vector<ll>> w;

ll dfs(ll k){
    vector<ll> depth(w[k].size());
    for(int i=0;i<w[k].size();i++){
        depth[i]=dfs(w[k][i]);
    }
    sort(depth.begin(),depth.end(),greater<ll>());
    ll mx=0;
    for(int i=0;i<w[k].size();i++){mx=max(mx,depth[i]+i+1);}
    return mx;
}


int main(){
    ll n;
    cin>>n;
    a.resize(n);
    w.resize(n);
    for(int i=1;i<n;i++){cin>>a[i]; a[i]--; w[a[i]].push_back(i);}
    cout<<dfs(0)<<endl;
    
    
    
    
    
    
    return 0;
}
