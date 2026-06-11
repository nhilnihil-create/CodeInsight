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
    unordered_map<char, vector<int>> pos;
    for(int i = 0; i < s.size(); i++) {
        pos[s[i]].push_back(i);
    }
    cout << (pos['Z'].back() - pos['A'][0] + 1) << endl;
    return 0;
}
