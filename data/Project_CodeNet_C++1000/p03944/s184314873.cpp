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
    int w, h, n;
    cin >> w >> h >> n;
    int mx_x = 0, mn_x = w;
    int mx_y = 0, mn_y = h;
    int x, y, a;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> a;
        if (a == 1) {
            mx_x = max(mx_x, x);
        } else if (a == 2) {
            mn_x = min(mn_x, x);
        } else if (a == 3) {
            mx_y = max(mx_y, y);
        } else {
            mn_y = min(mn_y, y);
        }
    }
    cout << max(0, mn_x-mx_x) * max(0, mn_y-mx_y) << endl;

    return 0;
}
