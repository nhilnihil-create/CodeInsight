#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = s.size() - 2; i >= 2; i -= 2) {
        if (s.substr(0, i / 2) == s.substr(i / 2, i / 2)) {
            cout << i << endl;
            return 0;
        }
    }
}
