#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    string T = "CODEFESTIVAL2016";
    int cnt = 0;
    for (int i = 0; i < S.length(); i++) if (S[i] != T[i]) cnt++;
    printf("%d\n", cnt);
}