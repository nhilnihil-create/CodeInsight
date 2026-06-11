#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, res;
    char ops;
    cin >> a >> ops >> b;
    if (ops == '+') res = a + b;
    else res = a - b;
    cout << res << endl;
}
