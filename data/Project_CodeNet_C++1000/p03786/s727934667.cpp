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
    vector<ll> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    sort(arr.begin(), arr.end());
    vector<ll> acc(n, 0);
    acc[0] = arr[0];
    for(int i = 1; i < n; i++) {
        acc[i] = acc[i-1] + arr[i];
    }
    int ans = 1;
    for(int i = arr.size()-2; i >= 0; i--) {
        if (acc[i]*2 >= arr[i+1])
            ans += 1;
        else
            break;
    }
    cout << ans << endl;
    return 0;
}


