#include <bits/stdc++.h>

using namespace std;

string s;

void solve() {
    for (int i = 0; i < int(s.size()); i++) {
        if (i % 2 == 0) {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

int main() {
    cin >> s;
    solve();
    return 0;
}