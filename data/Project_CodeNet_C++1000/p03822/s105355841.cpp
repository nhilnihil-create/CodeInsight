#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename Q_temp>
using smaller_queue = priority_queue <Q_temp, vector<Q_temp>, greater<Q_temp> >;

const ll MOD = (ll) (1e9 + 7);
//const ll MOD = 998244353;
const int INF = (int) 1e9;
const ll LINF = (ll) 4e18;
const double PI = acos(-1.0);

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbg2(x_) for(auto a_ : x_) cerr << a_ << " "; cerr << endl;
#define dbg3(x_ , sx_) rep(i, sx_) cerr << x_[i] << " "; cerr << endl;
vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

inline ll CEIL(ll a, ll b) {
    return (a + b - 1) / b;
}

void finish() {
    cout << -1 << endl;
    exit(0);
}

//------------------------------------------------------

vector<int> children[100010];

int dfs(int par) {
    if (children[par].empty()) return 0;
    vector<int> v;
    for (auto ch : children[par]) {
        v.push_back(dfs(ch) + 1);
    }
    sort(all(v));

    REP(i, 1, v.size()) {
        if (v[i - 1] >= v[i]) v[i] = v[i - 1] + 1;
    }
    return *v.rbegin();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << setiosflags(ios::fixed);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        children[par].push_back(i);
    }
    cout << dfs(1) << endl;
    return 0;
}

