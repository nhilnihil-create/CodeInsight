#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i] == s[j]) {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
    return 0;
}