#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int x = 0, max = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'I') {
            x++;
        } else {
            x--;
        }
        if (max < x) max = x;
    }

    cout << max << endl;

    return 0;
}
