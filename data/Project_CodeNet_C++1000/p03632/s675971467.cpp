#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int diff = min(B, D) - max(A, C);
    cout << max(0, diff) << endl;
}