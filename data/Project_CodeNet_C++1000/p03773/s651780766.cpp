#include <iostream>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    if (A + B > 23) printf("%d\n", (A + B) - 24);
    else printf("%d\n", A + B); 
}