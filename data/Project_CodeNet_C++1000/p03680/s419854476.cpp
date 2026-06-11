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
    int n;
    cin >> n;
    vector<int> arr(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int cur = 1, ans = 0;
    vector<int> visit(n+1, 0);
    visit[cur] = 1;
    while(cur != 2) {
        cur = arr[cur];
        ans += 1;
        if (visit[cur] == 1) {
            cout << -1 << endl;
            return 0;
        }
        visit[cur] = 1;
    }
    cout << ans << endl;
    return 0;
}
