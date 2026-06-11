#include "bits/stdc++.h"

using namespace std;

void Main() {
    string A, B, C;
    cin >> A >> B >> C;
    if (A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
