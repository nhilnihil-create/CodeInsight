#include <bits/stdc++.h>

using namespace std;


int main() {
    long long A, B, X;
    cin >> A >> B >> X;
    cout << B / X - (A != 0 ? (A - 1) / X : -1) << endl;
}
