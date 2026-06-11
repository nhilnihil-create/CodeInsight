#include "bits/stdc++.h"

using namespace std;

void Main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c || b + c == a || c + a == b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
