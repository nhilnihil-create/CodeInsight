#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    if(x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> ans(2 * n - 1, 0);
    set<int> se;
    for(int i = 1; i <= 2 * n - 1; i++) {
        se.insert(i);
    }
    for(int i = -1; i <= 1; i++) {
        ans[n - 1 + i] = x + i;
        se.erase(x + i);
    }
    for(int i = 0; i < 2 * n - 1; i++) {
        if(ans[i] == 0) {
            cout << *se.begin() << endl;
            se.erase(se.begin());
        } else {
            cout << ans[i] << endl;
        }
    }
}