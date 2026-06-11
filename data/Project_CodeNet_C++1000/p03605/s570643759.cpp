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
    for(char c: s) {
        if (c == '9') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
