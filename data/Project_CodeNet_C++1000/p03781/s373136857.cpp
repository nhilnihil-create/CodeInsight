#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    ull x;
    cin >> x;
    ull t = 1;
    while((t * (t - 1) >> 1) < x) {
        ++t;
    }
    cout << t - 1;
}