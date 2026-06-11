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
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int& val: arr)
        cin >> val;
    sort(arr.begin(), arr.end());
    ll mod = 1e9 + 7;
    if (n % 2 == 0) {
        for(int i = 0; i < n; i++) {
            if ((i/2)*2+1 != arr[i]) {
                cout << 0 << endl;
                return 0;
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            if (((i+1)/2)*2 != arr[i]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    ll ans = 1LL;
    for(int i = 0; i < n/2; i++)
        ans = (ans << 1) % mod;
    cout << ans << endl;
    return 0;
}


