//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long,long>>;

int main() {
    int N;
    ll A,B; cin >> N >> A >> B;
    vecl X(N);
    REP(i,N) cin >> X[i];
    ll ans = 0;
    if(B <= A) ans = B * (N-1);
    else {
        REP(i,N-1) {
            if((X[i+1]-X[i])*A >= B) ans += B;
            else ans += (X[i+1]-X[i])*A;
        }
    }
    cout << ans << endl;
}