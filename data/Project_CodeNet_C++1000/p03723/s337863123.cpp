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
    ll a, b, c;
    cin >> a >> b >> c;
    ll acc = a+b+c;
    unordered_set<string> used;
    auto tmp = to_string(a) + "_" + to_string(b) + " " + to_string(c);
    used.insert(tmp);
    ll ans = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        a = (acc-a)/2;
        b = (acc-b)/2;
        c = (acc-c)/2;
        ans += 1;
        auto tmp = to_string(a) + "_" + to_string(b) + " " + to_string(c);
        if (used.count(tmp) > 0) {
            cout << -1 << endl;
            return 0;
        }
        used.insert(tmp);
    }
    cout << ans << endl;
    return 0;
}
