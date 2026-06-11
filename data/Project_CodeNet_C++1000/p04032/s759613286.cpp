#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i]) {
            cout << i << ' ' << i + 1;
            return 0;
        }
    }
    for (int i = 2; i < s.length(); i++) {
        if (s[i - 2] == s[i]) {
            cout << i - 1 << ' ' << i + 1;
            return 0;
        }
    }
    cout << -1 << ' ' << -1;
}
