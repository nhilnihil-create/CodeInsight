#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;
    if (A + B >= 10) {
        cout << "error" << endl;
    }
    else {
        cout << A + B << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
