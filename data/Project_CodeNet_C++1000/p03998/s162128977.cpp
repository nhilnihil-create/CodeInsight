#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    string a, b, c;
    cin >> a >> b >> c;
    char now = a[0];
    a.erase(0, 1);
    while (1) {
        if (now == 'a') {
            if (a.empty()) {
                cout << "A" << endl;
                return 0;
            } else {
                now = a[0];
                a.erase(0, 1);
            }
        } else if (now == 'b') {
            if (b.empty()) {
                cout << "B" << endl;
                return 0;
            } else {
                now = b[0];
                b.erase(0, 1);
            }
        } else {
            if (c.empty()) {
                cout << "C" << endl;
                return 0;
            } else {
                now = c[0];
                c.erase(0, 1);
            }
        }
    }

    return 0;
}
