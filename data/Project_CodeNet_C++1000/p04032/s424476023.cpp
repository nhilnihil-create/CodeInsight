#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            printf("%d %d\n", i+1, i + 2);
            return 0;
        } else if (i + 2 < n && s[i] == s[i + 2]) {
            printf("%d %d\n", i+1, i + 3);
            return 0;
        }
    }
    puts("-1 -1\n");
    return 0;
}