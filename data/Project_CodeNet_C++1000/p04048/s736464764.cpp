// https://misteer.hatenablog.com/entry/AGC001-B
#include <iostream>
using namespace std;
using ll = long long;

long long reflect(ll A, ll B) {
    if(A > B) {
        swap(A, B);
    }
    long long ref = B / A;
    if(B % A == 0) {
        return (ref * 2 - 1) * A;
    } else {
        return ref * 2 * A + reflect(B % A, A);
    }
}

int main() {
    long long N, X;
    cin >> N >> X;
    cout << N + reflect(X, N - X) << endl;
    return 0;
}