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
    vector<int> arr = {399, 799, 1199, 1599, 1999, 2399, 2799, 3199, 9999};
    int n, val;
    cin >> n;
    unordered_map<int, int> color;
    for(int i = 0; i < n; i++) {
        cin >> val;
        auto it = lower_bound(arr.begin(), arr.end(), val);
        color[distance(arr.begin(), it)] += 1;
    }
    if (color.count(8) == 0) {
        cout << color.size() << " " << color.size() << endl;
    } else {
        int mn = max(int(color.size()-1), 1);
        int mx = int(color.size())+color[8]-1;
        cout << mn << " " << mx << endl;
    }
    return 0;
}
