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
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<vector<int>> v(m);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        v[x[i] % m].emplace_back(x[i]);
    }
    for(int i = 0; i < m; i++) {
        sort(ALL(v[i]));
    }
    int ans = 0;
    for(int j = 0; j <= m / 2; j++) {
        if(j == 0 || (m % 2 == 0 && j == m / 2)) {
            map<int, int> cnt;
            for(auto i : v[j]) {
                cnt[i]++;
                // cout << i << " ";
            }
            // cout << endl;
            int sum = 0, tmp = 0;
            for(auto p : cnt) {
                sum += p.second - (p.second / 2) * 2;
                tmp += p.second / 2;
            }
            tmp += sum / 2;
            // cout << tmp << endl;
            ans += tmp;
        } else {
            auto v1 = v[j];
            auto v2 = v[m - j];
            if(v1.size() > v2.size()) {
                swap(v1, v2);
            }
            // for(auto i : v1) {
            //     cout << i << " ";
            // }
            // cout << endl;
            // for(auto i : v2) {
            //     cout << i << " ";
            // }
            // cout << endl;
            int tmp = v1.size();
            int pcnt = 0;
            map<int, int> cnt;
            for(auto i : v2) {
                cnt[i]++;
            }
            for(auto p : cnt) {
                pcnt += p.second / 2;
            }
            int diff = v2.size() - v1.size();
            tmp += min(diff / 2, pcnt);
            ans += tmp;
        }
    }
    cout << ans << endl;
}