#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    for (int i = 0; i < S.length(); i += 2) printf("%c", S[i]);
    printf("\n");
}
