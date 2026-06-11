#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void mod(ll &val, ll M) {
    val = val % M;
    if(val < 0) {
        val += M;
    }
}

template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N,K;
    cin >> N >> K;
    vector<bitset<31>> A(N);
    vector<ll> B(N);
    for(int i = 0;i < N;i++) {
        int cnt;
        cin >> cnt;
        A.at(i) = cnt;
        cin >> B.at(i);
    }
    bitset<31> bit(K);
    ll ret = 0;
    for(int i = 0;i < 31;i++) {
        if(bit[i] == 0) {
            ll cost = 0;
            for(int j = 0;j < N;j++) {
                if((bit & A.at(j)) == A.at(j)) {
                    cost += B.at(j);
                }
            }
            chmax(ret,cost);
        }
        else {
            bitset<31> bit2 = bit;
            bit2[i] = 0;
            for(int j = 0;j < i;j++) {
                bit2[j] = 1;
            }
            ll cost = 0;
            for(int j = 0;j < N;j++) {
                if((bit2 & A.at(j)) == A.at(j)) {
                    cost += B.at(j);
                }
            }
            chmax(ret,cost);
        }
    }
    cout << ret << endl;
}