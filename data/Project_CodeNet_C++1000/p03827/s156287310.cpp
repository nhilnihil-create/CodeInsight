#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int x = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'I') {
            x++;
        }
        else {
            x--;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}