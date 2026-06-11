#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    if (s.size() < 4) {
        cout << "No" << endl;
    } else if (s.substr(0, 4) == "YAKI") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
