#include <bits/stdc++.h>

using namespace std;

string s;

void solve() {
    int max_z = 0;
    int min_a = 0;
    for (int i = 0; i < int(s.size()); ++i) {
        if (s[i] == 'A') {
            min_a = i;
            break;
        }
    }
    for (int i = int(s.size()); i > 0; i--) {
        if (s[i] == 'Z') {
            max_z = i;
            break;
        }
    }
    printf("%d", max_z - min_a + 1);
}

int main() {
    cin >> s;
    solve();
    return 0;
}