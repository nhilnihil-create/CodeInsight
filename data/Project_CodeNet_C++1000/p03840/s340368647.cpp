#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000010;
constexpr ll INF= 1000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P < 0) {
        return 0;
    }
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    ll I,O,T,J,L,S,Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    //実はI,O,J,Lだけで良い
    ll ret = O * 2;
    ll ret2 = 0;
    ret2 = max(ret2,ret + I / 2 * 4 + J / 2 * 4 + L / 2 * 4);
    if(I > 0 && J > 0 && L > 0) {
        ret2 = max(ret2,ret + 6 + (I - 1) / 2 * 4 + (J - 1) / 2 * 4 + (L - 1) / 2 * 4);
    }
    cout << ret2 / 2 << endl;
}