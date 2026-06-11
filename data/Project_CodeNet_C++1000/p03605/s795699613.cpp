#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    string ans = "No";
    if (s[0] == '9' || s[1] == '9') ans = "Yes";
    cout << ans << endl;
}