#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////


int main() {
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    ll dx = tx - sx, dy = ty - sy;
    rep(i, 0, dy) cout << "U";
    rep(i, 0, dx) cout << "R";
    rep(i, 0, dy) cout << "D";
    rep(i, 0, dx) cout << "L";
    cout << "L";
    rep(i, 0, dy+1) cout << "U";
    rep(i, 0, dx+1) cout << "R";
    cout << "DR";
    rep(i, 0, dy+1) cout << "D";
    rep(i, 0, dx+1) cout << "L";
    cout << "U" << endl;

    return 0;
}
