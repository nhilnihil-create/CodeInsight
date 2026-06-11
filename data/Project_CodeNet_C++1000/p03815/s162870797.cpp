#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll n, ans = 0;
    cin >> n;
    ll repeat = (n-1)/11;
    n -= repeat * 11;
    if (n <= 6) {
        cout << repeat*2 + 1 << endl;
    } else {
        cout << repeat*2 + 2 << endl;
    }
    return 0;
}

