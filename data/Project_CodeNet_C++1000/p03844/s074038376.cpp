#include <iostream>
using namespace std;
int main() {
    int A, B; char c; cin >> A >> c >> B;
    if (c == '+') printf("%d\n", A + B);
    else printf("%d\n", A - B);
}