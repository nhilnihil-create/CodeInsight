#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a; cin >> n >> a;
    n += a;
    if (n > 23) n -= 24;
    cout << n << endl;
}
