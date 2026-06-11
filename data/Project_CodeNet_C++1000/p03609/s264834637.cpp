#include <iostream>
using namespace std;
int main() {
    long long int X, t; cin >> X >> t;
    if (X - t >= 0) printf("%d\n", X - t);
    else printf("%d\n", 0);
}