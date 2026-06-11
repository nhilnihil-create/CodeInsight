#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
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

int main() {
    string S,T;
    cin >> S >> T;
    int s = S.size();
    int t = T.size();
    vector<int> ss(s + 1);
    vector<int> tt(t + 1);
    for(int i = 0;i < s;i++) {
        if(S.at(i) == 'A') {
            ss.at(i + 1) = ss.at(i) + 1;
        }
        else {
            ss.at(i + 1) = ss.at(i) + 2;
        }
    }
    for(int i = 0;i < t;i++) {
        if(T.at(i) == 'A') {
            tt.at(i + 1) = tt.at(i) + 1;
        }
        else {
            tt.at(i + 1) = tt.at(i) + 2;
        }
    }
    int Q;
    cin >> Q;
    for(int i = 0;i < Q;i++) {
        int A,B,C,D;
        cin >> A >> B >> C >> D;
        int cnt1 = ss.at(B) - ss.at(A - 1);
        int cnt2 = tt.at(D) - tt.at(C - 1);
        if(cnt1 % 3 == cnt2 % 3) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}