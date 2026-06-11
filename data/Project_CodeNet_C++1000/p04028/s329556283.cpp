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


ll mod_pow(ll a,ll x){
    ll ret=1;
    while(x>0){
        if(x&1){(ret*=a)%=MOD;}
        (a*=a)%=MOD;
        x>>=1;
    }
    return ret;
}


int main(){
    const ll inv=(1+MOD)/2;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        vector<ll> next(n+1,0);
        for(int t=0;t<=n;t++){
            if(t!=0){next[t-1]+=dp[t]; next[t-1]%=MOD;}
            else{next[t]+=dp[t]; next[t]%=MOD;}
            if(t!=n){next[t+1]+=dp[t]*2; next[t+1]%=MOD;}
        }
        dp=next;
    }
    cout<<dp[s.size()]*mod_pow(inv,s.size())%MOD<<endl;
    
    return 0;
}
