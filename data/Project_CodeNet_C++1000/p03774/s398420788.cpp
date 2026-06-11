#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<pair<ll, ll>> student;
    vector<pair<ll, ll>> ckpt;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        student.push_back({u, v});
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        ckpt.push_back({u, v});
    }
    for(int i = 0; i < n; i++) {
        ll dis = INT_MAX;
        int ans = 0;
        for(int j = 0; j < m; j++) {
            ll tmp = llabs(student[i].first - ckpt[j].first) + llabs(student[i].second - ckpt[j].second);
            if (tmp < dis) {
                dis = tmp;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
