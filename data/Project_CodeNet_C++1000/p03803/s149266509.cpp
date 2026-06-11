#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B;
    cin >> A >> B;

    if (A == 1 && B == 1) {
        cout << "Draw" << endl;
    } else if (A == 1) {
        cout << "Alice" << endl;
    } else if (B == 1) {
        cout << "Bob" << endl;
    } else if (A == B) {
        cout << "Draw" << endl;
    } else if (A < B) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }

    return 0;
}