#include <iostream>
#include <string>
using namespace std;
int main() {
    string S; cin >> S;
    string T = "YAKI", F = S.substr(0, 4);
    if (T == F) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}