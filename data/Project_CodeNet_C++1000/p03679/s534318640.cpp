#include "bits/stdc++.h"

using namespace std;

void Main() {
    int X, A, B;
    cin >> X >> A >> B;
    if (B - A <= 0) {
        cout << "delicious" << endl;
    }
    else if (B - A <= X) {
        cout << "safe" << endl;
    }
    else {
        cout << "dangerous" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
