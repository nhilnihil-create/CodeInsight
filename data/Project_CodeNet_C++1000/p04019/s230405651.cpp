#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    bool w = false, e = false, n = false, s = false;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == 'S') s = true;
        if (S[i] == 'N') n = true;
        if (S[i] == 'W') w = true;
        if (S[i] == 'E') e = true;
    }
    if ((s == true && n == true && e == false && w == false) || (s == true && n == true && e == true && w == true) || (s == false && n == false && e == true && w == true)) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}
