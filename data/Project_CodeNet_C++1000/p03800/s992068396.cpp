#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < 4; ++i) {
        vector<int> d(n + 1);
        d.at(0) = (i & 1), d.at(1) = ((i & 2) >> 1);
        for (int i = 1; i < n; ++i) d.at(i + 1) = ((s.at(i) == 'x') ^ d.at(i) ^ d.at(i - 1));
        if (d.at(0) == d.at(n) && ((d.at(1) != d.at(n - 1)) ^ d.at(0) ^ (s.at(0) == 'o'))) {
            for (int i = 0; i < n; ++i) cout << (d.at(i) ? 'W' : 'S');
            cout << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
