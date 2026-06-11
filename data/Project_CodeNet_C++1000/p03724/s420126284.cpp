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
    ll n, m; cin >> n >> m;
    vll a(m), b(m);
    rep(i, 0, m){
        cin >> a[i] >> b[i];
    }
    vll imos(n+1, 0);
    rep(i, 0, m){
        imos[a[i]]++;
        imos[b[i]]--;
    }
    ll s = 0;
    vll p(n);
    rep(i, 1, n){
        s += imos[i];
        p[i] = s;
    }
    bool v = true;
    rep(i, 1, n){
        if(p[i]%2 == 1){
            v = false;
        }
    }
    if(v){
        prtl("YES");
    }else{
        prtl("NO");
    }
}

