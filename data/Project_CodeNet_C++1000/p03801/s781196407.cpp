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




int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &I:a){cin>>I;}
    priority_queue<pll> Q;
    for(int i=0;i<n;i++){
        Q.push({a[i],n-i});
    }
    ll cnt=1;
    pll mi=Q.top();
    Q.pop();
    vector<ll> ans(n,0);
    while(!Q.empty()){
        pll w=Q.top();
        Q.pop();
        if(n-w.S>n-mi.S){
            ans[n-mi.S]+=cnt*(mi.F-w.F);
            mi.F=w.F; cnt++;
        }
        else{
            ans[n-mi.S]+=cnt*(mi.F-w.F);
            mi=w; cnt++;
        }
    }
    ans[n-mi.S]+=cnt*(mi.F);
    for(auto &I:ans){cout<<I<<endl;}
    
    
    
    
    
    return 0;
}
