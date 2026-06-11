#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B;
    char op;
    cin >> A >> op >> B;

    if (op == '+') {
        cout << A + B << endl;
    } else if (op == '-') {
        cout << A - B << endl;
    }

    return 0;
}