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
    vector<int> arr(3, 0);
    for(auto& val: arr)
        cin >> val;
    cout << accumulate(arr.begin(), arr.end(), 0) - *max_element(arr.begin(), arr.end()) << endl;
    return 0;
}
