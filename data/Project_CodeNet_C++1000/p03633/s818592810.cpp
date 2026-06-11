#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;

ll gcd(ll a,ll b){
    ll M=max(a,b);
    ll m=min(a,b);
    if(m==0){
        return M;
    }
    return gcd(m,M%m);
}


ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

int main(){
    int n;
    cin>>n;
    ll a;
    ll ans=1;
    for(int i=0;i<n;i++){
        cin>>a;
        ans=lcm(ans,a);

    }
    cout<<ans<<endl;

    
}