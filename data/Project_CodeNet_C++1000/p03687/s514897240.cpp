#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
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




////////////////////////////////////////////////////////


int main() {
    string s; cin >> s;
    ll ans = 100;
    rep(i, 0, 26){
        char c = 'a' + i;
        ll dis = 0;
        ll bf = 0;
        bool f = true;
        rep(j, 0, sz(s)){
            if(s[j] == c){ 
                if(bf == 0 && f){ dis = j; f = false;}
                chmax(dis, j-bf-1);
                bf = j;
            }
        }
        chmax(dis, sz(s)-1-bf);
        chmin(ans, dis);
    }
    co(ans);

    return 0;
}
