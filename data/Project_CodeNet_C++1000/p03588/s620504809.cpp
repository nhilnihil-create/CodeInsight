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
    ll n, a, b, cur_max = 0, ans = 0;
    cin >> n;
    for(int i = 0; i< n; i++) {
        cin >> a >> b;
        if (a > cur_max) {
            cur_max = a;
            ans = a + b;
        }
    }
    cout << ans << endl;
    return 0;
}
