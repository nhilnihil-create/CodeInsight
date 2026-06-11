#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << max(A * B, C * D) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
