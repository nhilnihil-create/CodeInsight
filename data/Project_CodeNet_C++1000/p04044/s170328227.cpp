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
    int n, l;
    cin >> n >> l;
    vector<string> strs;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        strs.push_back(s);
    }
    sort(strs.begin(), strs.end());
    string ans = "";
    for(auto s: strs) {
        ans += s;
    }
    cout << ans << endl;
    return 0;
}
