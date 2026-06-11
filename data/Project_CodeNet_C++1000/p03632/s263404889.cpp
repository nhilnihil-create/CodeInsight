#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int start = max(A, C);
    int end = min(B, D);
    int time = end - start;

    if (time >= 0) {
        cout << time << endl;
    } else {
        cout << "0" << endl;
    }
}