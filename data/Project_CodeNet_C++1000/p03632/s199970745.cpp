#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int start = max(A, C);
    int end = min(B, D);
    int ans = end - start;
    if (ans > 0) {
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}