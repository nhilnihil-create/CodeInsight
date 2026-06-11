#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    for (char c : S) if (c == ',') printf(" "); else printf("%c", c);
    printf("\n");
}