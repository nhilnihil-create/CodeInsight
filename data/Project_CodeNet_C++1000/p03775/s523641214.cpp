#include <iostream>
#include <cmath>
using namespace std;
using llong = long long;

int func(llong A, llong B) {
    llong C = max(A, B);
    int d = 0;
    while(C > 0) {
        C /= 10;
        ++d;
    }
    return d;
}

int main() {
    llong N;
    cin >> N;
    llong thresh = round(sqrt(N));
    llong A = 1, B;
    int fMin = 20;
    while (A <= thresh) {
        if (N%A == 0) {
            B = N / A;
            fMin = min(fMin, func(A, B));
        }
        ++A;
    }
    cout << fMin << endl;
}
