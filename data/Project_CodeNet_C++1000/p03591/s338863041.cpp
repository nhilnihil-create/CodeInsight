#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin >> s;
    if (s.length() >= 4 && s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I') {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}