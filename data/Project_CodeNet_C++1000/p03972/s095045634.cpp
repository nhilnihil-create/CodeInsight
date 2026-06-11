#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, m;
    cin >> n >> m;
    vector <int> p(n), q(m);

    vector <ii> v;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        v.app(mp(p[i], 0));
    }
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
        v.app(mp(q[i], 1));
    }

    sort(all(v));

    vector <int> cnt(2);
    int ans = 0;
    for (auto e : v) {
        if (e.s == 0) {
            ans += e.f * (m + 1 - cnt[1]);
        }
        else {
            ans += e.f * (n + 1 - cnt[0]);
        }   

        cnt[e.s]++;

    }   
    cout << ans << endl;
}
