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
    int k, s;
    cin >> k >> s;
    ll ans = 0;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= k; j++) {
            if (s-i-j >= 0 && s-i-j <= k)
                ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
