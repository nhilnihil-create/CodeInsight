#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t; cin >> s >> t;
    vll accs(s.size()+1, 0), acct(t.size()+1);
    REP(i, s.size()) {
        if (s[i] == 'A') accs[i+1] = accs[i] + 1;
        else accs[i+1] = accs[i] + 2; 
    }
    REP(i, t.size()) {
        if (t[i] == 'A') acct[i+1] = acct[i] + 1;
        else acct[i+1] = acct[i] + 2; 
    }
    ll q; cin >> q;
    ll a, b, c, d;
    REP(_, q) {
        cin >> a >> b >> c >> d;
        if ((accs[b]-accs[a-1])%3 == (acct[d]-acct[c-1])%3) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
