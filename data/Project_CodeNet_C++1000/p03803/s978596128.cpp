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
    vector<int> arr(2, 0);
    for(auto& val: arr) {
        cin >> val;
        if (val == 1)
            val += 100;
    }
    if (arr[0] > arr[1])
        cout << "Alice" << endl;
    else if (arr[0] < arr[1])
        cout << "Bob" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}
