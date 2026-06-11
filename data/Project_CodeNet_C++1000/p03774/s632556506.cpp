#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const ll INF = 1LL << 60;

int main() {
    int N,M; cin >> N >> M;
    vecl A(N),B(N),C(M),D(M),a(N),b(N);
    REP(i,N) cin >> A[i] >> B[i];
    REP(i,M) cin >> C[i] >> D[i];
    REP(i,N) {
        ll x = A[i];
        ll y = B[i];
        ll ans  = INF;
        for(int j = M-1; j>= 0; --j) {
            ll d = abs(x-C[j]) + abs(y-D[j]);
            if(d <= ans) {
                ans = d;
                a[i] = j+1;
            }
        }
    }
    REP(i,N) cout << a[i] << endl;
}