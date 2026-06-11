#include <iostream>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    if (A + B < 10) printf("%d\n", A + B);
    else printf("%s\n", "error");
}