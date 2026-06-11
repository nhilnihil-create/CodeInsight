#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    int N = S.length();
    printf("%c%d%c\n", S[0], N - 2, S[N - 1]);
}
