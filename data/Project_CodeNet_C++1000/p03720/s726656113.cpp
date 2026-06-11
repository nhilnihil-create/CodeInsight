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
    vector<int> ans(n, 0);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        ans[u-1] += 1;
        ans[v-1] += 1;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;

    return 0;
}
