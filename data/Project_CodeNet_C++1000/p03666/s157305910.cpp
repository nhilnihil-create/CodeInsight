#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
 
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
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    B = abs(A - B);
    A = 0;
    N--;
    ll left = -N * D;
    ll right = -N * C;
    bool ret = false;
    for(int i = 0;i < N - 1;i++) {
        if(left <= B && B <= right) {
            ret = true;
        }
        left += C + D;
        right += C + D;
    }
    if(ret == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}