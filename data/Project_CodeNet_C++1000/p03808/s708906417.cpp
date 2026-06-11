#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

bool solve(ll N, const vector<ll> &a) {
    ll S = 0;
    rep(i, N) S += a[i];
    if (S % (N * (N + 1)/2) != 0) return false;
    ll num = S / (N * (N + 1)/2);
    rep(i, N) {
        ll b = a[(i+1)%N] - a[i] - num;
        if (b % N != 0 || b > 0) return false;
    }
    return true;
}


int main() {
    ll N; cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    if (solve(N, a)) cout << "YES" << endl;
    else cout << "NO" << endl;
}