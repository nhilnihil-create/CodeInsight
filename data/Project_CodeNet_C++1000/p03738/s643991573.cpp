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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() < s2.size()) {
        cout << "LESS" << endl;
    } else if (s1.size() > s2.size()) {
        cout << "GREATER" << endl;
    } else {
        if (s1 < s2)
            cout << "LESS" << endl;
        else if (s1 > s2)
            cout << "GREATER" << endl;
        else
            cout << "EQUAL" << endl;
    }
    return 0;
}
