#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S; char c = 'a';
    sort(S.begin(), S.end());
    for (int i = 0; i < S.length(); ++i) {
        if (c == S[i]) c = (char)((int)c + 1);
    }
    if (c > 'z') printf("%s\n", "None");
    else printf("%c\n", c);
}
