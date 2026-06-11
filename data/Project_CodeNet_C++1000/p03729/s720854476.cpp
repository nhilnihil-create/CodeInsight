#include <iostream>
using namespace std;
int main() {
    string A, B, C; cin >> A >> B >> C;
    int a = A.length(), b = B.length();
    if (A[a - 1] == B[0] && B[b - 1] == C[0]) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}