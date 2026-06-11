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
    string s;
    cin >> s;
    string ans = "";
    for(char c: s) {
        if (c != 'B')
            ans += c;
        else {
            if (!ans.empty())
                ans.pop_back();
        }
    }
    cout << ans << endl;


    return 0;
}
