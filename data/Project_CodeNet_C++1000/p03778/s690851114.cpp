#include <bits/stdc++.h>
using namespace std;
int main() {
    int w, a, b, aw, bw;
    cin >> w >> a >> b;
    aw = a + w;
    bw = b + w;
    if (aw < b) cout << b - aw;
    else if (bw < a) cout << a - bw;
    else cout << '0';
}