#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll X,Y; cin >> X >> Y;
    bool alice = (llabs(X-Y) >= 2);
    cout << (alice ? "Alice" : "Brown") << endl;
    return 0;
}
