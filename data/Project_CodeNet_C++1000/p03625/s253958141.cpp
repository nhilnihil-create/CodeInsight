#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
# define ll int64_t
# define str string
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
# define PI 3.141592653589793
# define vec vector
#define dump(x) cerr<<#x<<"="<<x<<endl
using namespace std;

#define INF 2000000000
#define MAX_V 10



bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll modpow(ll a,ll n,ll mod1) {
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod1;
        a = a*a%mod1;
        n >>= 1;
    }
    return res;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) (x*=i)%=mod;
    return x;
}

ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b,a%b));
}

ll lcm(ll a,ll b){
   return a/gcd(a,b)*b;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    
    ll n;
    cin>>n;
    map<ll,ll> dp;
    rep(i,n){
        ll a;
        cin>>a;
        dp[a]++;
    }
    
    vec<ll> e;
    for(auto p:dp){
        while(p.second>=2){
            e.pb(p.first);
            p.second-=2;
        }
    }
    sort(ALL(e));
    if(e.size()<1) cout<<0<<endl;
    else cout<<e[e.size()-1]*e[e.size()-2]<<endl;
    return 0;
}
