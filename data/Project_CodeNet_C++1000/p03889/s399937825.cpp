#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int n = s.size();
    map<int, int> m = {{'b', 'd'}, {'d', 'b'}, {'p', 'q'}, {'q', 'p'}};
    for (int i = 0; i < n; i++) {
        if (s[i] != m[s[n-i-1]]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}