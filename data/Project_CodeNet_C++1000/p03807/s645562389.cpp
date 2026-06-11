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
    vector<int> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    vector<int> parity(2, 0);
    for(auto& val: arr) {
        parity[val%2] += 1;
    }
    if (parity[1] % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
