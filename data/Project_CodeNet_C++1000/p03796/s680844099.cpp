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
    ll mod = 1e9 + 7;
    ll fac = 1;
    for(int i = 1; i <= n; i++) {
        fac *= ll(i);
        fac %= mod;
    }
    cout << fac << endl;
    return 0;
}
