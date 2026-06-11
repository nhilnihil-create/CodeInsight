#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a, b, c;
    c = N % 10;
    b = (N / 10) % 10;
    a = (N / 100) % 10;
    int rev = 100 * c + 10 * b + a;

    if (N == rev) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}