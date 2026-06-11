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
    for(int& val: arr) {
        cin >> val;
        val--;
    }
    ll ans = 0, consc = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] == i) {
            consc += 1;
        } else {
            ans += (consc+1) / 2;
            consc = 0;
        }
    }
    ans += (consc+1) / 2;
    cout << ans << endl;
    return 0;
}


