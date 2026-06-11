#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    string op;
    cin >> A >> op >> B;
    if (op == "+") {
        cout << A + B << endl;
    }
    else {
        cout << A - B << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
