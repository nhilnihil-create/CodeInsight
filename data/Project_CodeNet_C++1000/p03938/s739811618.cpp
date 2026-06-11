#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;
ll l = 1000000000;

int main(){
    ll n; cin >> n;
    vll p(n);
    rep(i, 0, n){
        cin >> p[i];
    }
    vll sum(n);
    rep(i, 0, n){
        sum[p[i]-1] = l-n+i;
    }
    vll a(n), b(n);
    ll f = 1;
    rep(i, 0, n){
        a[i] = f;
        f += n;
        b[i] = sum[i] - a[i];
    }
    rep(i, 0, n){
        prt(a[i]); prt(" ");
    }
    prt(endl);
    rep(i, 0, n){
        prt(b[i]); prt(" ");
    }
}

