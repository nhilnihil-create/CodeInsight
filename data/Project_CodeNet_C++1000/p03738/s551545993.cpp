#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() > b.size())
        cout << "GREATER" << endl;
    else if (a.size() < b.size())
        cout << "LESS" << endl;
    else if (a == b)
        cout << "EQUAL" << endl;
    else {
        rep(i, a.size()) {
            int A = a[i] - '0';
            int B = b[i] - '0';
            if (A > B) {
                cout << "GREATER" << endl;
                break;
            } else if (A < B) {
                cout << "LESS" << endl;
                break;
            }
        }
    }

    return 0;
}
