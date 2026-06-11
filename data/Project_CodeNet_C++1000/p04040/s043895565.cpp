


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;


const int mod=1000000007;
//const int mod=998244353;


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<long long int> fact,fact_inverse;
template<typename type>
void tabulate(type n){
    fact.resize(n+1);
    fact_inverse.resize(n+1);
    fact[0]=1;
    fact_inverse[0]=binpow(1, mod-2, mod);
    for (int i=1; i<n+1; i++) {
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
        fact_inverse[i]=binpow(fact[i], mod-2, mod);
    }
}
template<typename type>
long long int nCk(type n,type k){
    return fact[n]*fact_inverse[n-k]%mod*fact_inverse[k]%mod;
}
template<typename type>
long long int nPk(type n,type k){
    return fact[n]*fact_inverse[n-k]%mod;
}

int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t,n,m,k,q,x,a,b,c,d,y,l,r;
    tabulate(2e5+100);
    cin >> n >> m >> a >> b;
    a=n-a;
    ll ans=0;
    for(ll i=1; i<=a; i++){
        ans+=nCk(i+b-2,i-1)*nCk(n+m-i-b-1,n-i)%mod;
        ans%=mod;
    }
    cout << ans << el;
    return 0;
}
