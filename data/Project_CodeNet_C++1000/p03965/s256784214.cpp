#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int p = 0, g = 0, ans = 0;
    for (auto& e : s) {
        if (e == 'p') {
            if (p < g) {
                p++;
            } else {
                g++;
                ans--;
            }
        } else {
            if (p < g) {
                p++;
                ans++;
            } else {
                g++;
            }
        }
    }

    cout << ans << endl;
}
