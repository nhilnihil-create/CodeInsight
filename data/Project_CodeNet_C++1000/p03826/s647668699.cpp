#include <iostream>
using namespace std;
int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    printf("%d\n", max(A * B, C * D));
}