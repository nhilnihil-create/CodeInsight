#include <bits/stdc++.h>

int X;
using namespace std;
int getClosestGauss(int X) {
    int i;
    for (i = 0; i* (i + 1)/2 < X; i++) {
    }
    return i;
}
int main() {
    cin >> X;
    cout << getClosestGauss(X);
    return 0;
}