//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n, m;
    cin >> n >> m;

    vi G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a]++;
        G[b]++;
    }

    rep(i, n) {
        if(G[i]&1)  {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}