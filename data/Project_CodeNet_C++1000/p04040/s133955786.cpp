#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll mod=1000000007;
ll combi(ll N_, ll C_) {
    const int NUM_=400001;
    static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
    if (fact[0]==0) {
        inv[1]=fact[0]=factr[0]=1;
        for (int i=2;i<=NUM_;++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mod, factr[i]=factr[i-1]*inv[i]%mod;
    }
    if(C_<0 || C_>N_) return 0;
    return factr[C_]*fact[N_]%mod*factr[N_-C_]%mod;
}

int main(){
    ll h,w;
    ll a,b;
    cin >> h >> w >> a >> b;
    ll ans = 0;
    for(ll i = b+1; i <= w; i++){
        ans += combi(h-a-1+i-1,h-a-1)*combi(a-1+w-i,a-1);
        ans %= mod;
    }
    cout << ans << endl;
}