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

int main(){
    ll N, X; cin >> N >> X;
    ll res = N;
    ll a = max(N - X, X), b = min(N - X, X);

    while (b) {
        ll q = a/b;
        ll r = a % b;
        res += (b * 2) * q;
        if (r == 0) res -= b;
        a = b, b = r;
    }

    cout << res << endl;
}