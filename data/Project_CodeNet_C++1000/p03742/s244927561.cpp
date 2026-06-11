#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll X, Y;
    cin >> X >> Y;
    if (abs(X-Y) <= 1) cout << "Brown\n";
    else cout << "Alice\n";
    return 0;
}