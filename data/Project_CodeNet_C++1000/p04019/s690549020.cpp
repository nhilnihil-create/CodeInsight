#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int d[4] = {0};  // N W S E
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') {
            d[0]++;
        } else if (s[i] == 'W') {
            d[1]++;
        } else if (s[i] == 'S') {
            d[2]++;
        } else {
            d[3]++;
        }
    }

    if (d[0] * d[2] == 0 && d[0] != d[2]) {
        puts("No");
    } else if (d[1] * d[3] == 0 && d[1] != d[3]) {
        puts("No");
    } else {
        puts("Yes");
    }
}
