#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, A, B;
    cin >> X >> A >> B;
    if (B-A<=0) cout << "delicious\n";
    else if (B-A<=X) cout << "safe\n";
    else cout << "dangerous\n";
}