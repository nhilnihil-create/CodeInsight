#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    queue<ll> que;
    rep(i, n) {
        ll t = a[i];
        int b = 0;
        while(t == a[i]) {
            ++b;
            ++i;
        }
        if (b >= 4 && (int)que.size() == 0) {
            cout << t * t << endl;
            return 0;
        }
        if (b >= 2) que.push(t);
        --i;
        if ((int)que.size() >= 2) break;
    }

    if ((int)que.size() <= 1) {
        cout << 0 << endl;
        return 0;
    }
    
    ll edge1 = que.front();
    que.pop();
    ll edge2 = que.front();

    cout << edge1 * edge2 << endl;

    return 0;
}