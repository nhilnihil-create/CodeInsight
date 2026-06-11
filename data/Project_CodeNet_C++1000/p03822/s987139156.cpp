#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int n;
map<int, vector<int>> m;

int rec(int root) {
    vector<int> ds;
    for (auto c: m[root]) {
        ds.push_back(rec(c));
    }
    sort(rall(ds));
    int d = 0;
    rep(i, ds.size()) {
        d = max(d, ds[i] + i);
    }
    return d + 1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin>>n;
    rep(i, n - 1) {
        int a;
        cin>>a;
        m[a].push_back(i + 2);
    }

    cout << rec(1) - 1 << endl;

    return 0;
}
