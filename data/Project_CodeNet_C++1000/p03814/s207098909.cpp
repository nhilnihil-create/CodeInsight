#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string s; cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            a = i; break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            b = i; break;
        }
    }
    printf("%d\n", b - a + 1);
}
