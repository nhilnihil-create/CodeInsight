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
    vector<int> arr(26, 0);
    for(char c: s)
        arr[c-'a'] += 1;
    for(int i = 0; i < 26; i++)
    if (arr[i] == 0) {
        cout << char('a'+i) << endl;
        return 0;
    }
    cout << "None" << endl;
    return 0;
}
