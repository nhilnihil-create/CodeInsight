#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> vv;
    vector<int> v = {1,3,5,7,8,10,12};
    vector<int> v1 = {4,6,9,11};
    vector<int> v2 = {2};
    vv.push_back(v);
    vv.push_back(v1);
    vv.push_back(v2);
    for (int i = 0; i < 3; i++) {
        if (find(bn(vv[i]), a) != vv[i].end() && find(bn(vv[i]), b) != vv[i].end()) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";

}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
