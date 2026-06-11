#include "bits/stdc++.h"

using namespace std;

void Main() {
    vector<int> A(3, 0);
    cin >> A[0] >> A[1] >> A[2];

    sort(A.begin(), A.end());
    if (A[0] == 5 && A[1] == 5 && A[2] == 7) {
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
