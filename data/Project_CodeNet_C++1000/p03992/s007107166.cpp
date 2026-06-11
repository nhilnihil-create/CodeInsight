#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    for (int i = 0; i < S.length(); i++) {
        printf("%c", S[i]);
        if (i == 3) printf(" ");
    }
    printf("\n");
}