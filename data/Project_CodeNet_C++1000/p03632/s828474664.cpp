#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int N = max(B, D);
    bool alice = false, bob = false;
    int count = 0;

    for (int i = 0; i <= N; i++) {
        if (i == A) alice = true;
        if (i == C) bob = true;
        if (i == B) alice = false;
        if (i == D) bob = false;
        if (alice && bob) count++;
    }
    cout << count << endl;
}