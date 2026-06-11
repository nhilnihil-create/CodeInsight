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

int main(){
    ll n, k; cin >> n >> k;
    vll a(n);
    ll mx = 0;
    bool b = false;
    set<ll> s;
    rep(i, 0, n){
        cin >> a[i];
        s.insert(a[i]);
        if(a[i] == k){
            b = true;
        }
        chmax(mx, a[i]);
    }
    if(k > mx){
        prtl("IMPOSSIBLE");
        return 0;
    }
    if(b){
        prtl("POSSIBLE");
        return 0;
    }
    sort(a.begin(),a.end());
    ll g = __gcd(a[0], a[1]);
    rep(i, 2, n){
        g = __gcd(g, a[i]);
    }
    if(k%g == 0){
        prtl("POSSIBLE");
    }else{
        prtl("IMPOSSIBLE");
    }
}

