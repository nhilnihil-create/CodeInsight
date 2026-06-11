#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string s, ans = ""; cin >> s;
    for (int i = 0; i < s.length(); i++) {
       if (s[i] == '0') ans += '0';
       if (s[i] == '1') ans += '1';
       if (s[i] == 'B' && ans.length() > 0) ans.pop_back();
    }
    cout << ans << endl;
}
