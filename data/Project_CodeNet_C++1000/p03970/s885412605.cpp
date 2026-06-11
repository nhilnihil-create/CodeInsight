#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
    cin >> s;
    string t = "CODEFESTIVAL2016";
    int ans = 0;
    for (int i = 0; i < 16; ++i) {
        if(s[i] == t[i]) continue;
        ans++;
    }
    cout << ans << endl;
}
