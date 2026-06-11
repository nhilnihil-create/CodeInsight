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
    int k, t;
    cin >> k >> t;
    vector<int> arr(t, 0);
    for(auto& val: arr)
        cin >> val;
    int mx = *max_element(arr.begin(), arr.end());
    int rem = k - mx;
    if (mx > rem+1) {
        mx -= (rem+1);
        cout << mx << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}


