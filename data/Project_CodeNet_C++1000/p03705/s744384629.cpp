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
    ll n, a, b;
    cin >> n >> a >> b;
    if (a > b || (n == 1 && a != b)) {
        cout << 0 << endl;
    } else {
        cout << b*(n-2) - a*(n-2) + 1 << endl;
    }
    return 0;
}
