#include <iostream>
using namespace std;
int main() {
    int N, K, X, Y; cin >> N >> K >> X >> Y;
    if (N - K >= 0) printf("%d\n", K * X + (N - K) * Y);
    else printf("%d\n", N * X);
}