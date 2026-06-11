#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin >> a;
    char op;
    cin >> op;
    int b;
    cin >> b;

    if (op == '+') {
        cout << a + b << endl;
    } else {
        cout << a - b << endl;
    }
    return 0;
}