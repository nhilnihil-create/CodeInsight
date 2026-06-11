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
    string s1, s2, ans = "";
    cin >> s1 >> s2;
    int i2 = 0;
    for(int i = 0; i < s1.size(); i++) {
        ans += s1[i];
        if (i2 < s2.size())
            ans += s2[i2++];
    }
    cout << ans << endl;
    return 0;
}
