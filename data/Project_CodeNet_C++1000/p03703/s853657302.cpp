#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef tuple<int,int,int> TP;

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

ll merge_cnt(vector<ll> &a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<ll> b(a.begin(), a.begin()+n/2);
    vector<ll> c(a.begin()+n/2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    for(int i = 0;i < N;i++) {
        vec.at(i) -= K;
    }
    vector<ll> Sum(N + 1);
    for(int i = 0;i < N;i++) {
        Sum.at(i + 1) = Sum.at(i) + vec.at(i);
    }
    ll ret = merge_cnt(Sum);
    ll ret2 = 0;
    for(ll i = 0;i <= N;i++) {
        ret2 += i;
    }
    cout << ret2 - ret << endl;
}