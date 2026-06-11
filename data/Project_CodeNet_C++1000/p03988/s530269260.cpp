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
    ll n; cin >> n;
    map<ll, ll> ac;
    REP(i, n) {
        ll a; cin >> a;
        ac[a]++;
    }
    ll maxa = (*(--ac.end())).first;
    if ((maxa % 2 == 1 && ac[(maxa+1)/2] != 2) || (maxa % 2 == 0 && ac[maxa/2] != 1)) cout << "Impossible\n";
    else {
        ll prev = -1;
        for (P<ll, ll> acc: ac) {
            if ((maxa%2==0 && acc.first < maxa/2) || (maxa%2==1 && acc.first < (maxa+1)/2)) {
                cout << "Impossible\n"; return 0;
            }
            if (prev == -1) {
                prev = acc.first;
                continue;
            }
            if (acc.first != prev+1 || acc.second < 2) {
                cout << "Impossible\n"; return 0;
            }
            prev = acc.first;
        }
        cout << "Possible\n";
    }
    return 0;
}
