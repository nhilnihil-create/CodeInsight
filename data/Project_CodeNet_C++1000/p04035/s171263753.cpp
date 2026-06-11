#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

int main(int argc, char const *argv[]) {
    int n,l; cin>>n>>l;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    int idx = INF;
    rep(i,n-1) {
        if (a[i]+a[i+1] >= l) {
            idx = i;
            break;
        }
    }

    if (idx==INF) {
        cout << "Impossible" << '\n';
        return 0;
    }

    vector<int> ans;
    for (int i = idx+1; i < n; ++i) {
        ans.push_back(i);
    }
    for (int i = idx; i > 0; --i) {
        ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());
    cout << "Possible" << '\n';
    for (auto &&e: ans) cout << e << '\n';
    return 0;
}