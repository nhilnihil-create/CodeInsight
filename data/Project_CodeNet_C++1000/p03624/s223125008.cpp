#include <bits/stdc++.h>

using namespace std;

string s;

void solve() {
    int values[26] = {0};
    for (char i : s) {
        values[i - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (values[i] == 0) {
            printf("%c\n", 'a' + i);
            return;
        }
    }
    printf("None\n");
}

int main() {
    cin >> s;
    solve();
    return 0;
}