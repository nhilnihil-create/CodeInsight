#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    sort(S.begin(), S.end());
    for (int i = 0; i < S.length() - 1; ++i) {
        if (S[i] == S[i + 1]) {
            printf("%s\n", "no");
            return 0;
        }
    }
    printf("%s\n", "yes");
    return 0;
}
