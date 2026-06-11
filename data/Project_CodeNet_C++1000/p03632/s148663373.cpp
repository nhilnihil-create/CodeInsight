#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int diff = min(B, D) - max(A, C);
    if (diff >=0)
        cout << diff << endl;
    else
        cout << 0 << endl;
}