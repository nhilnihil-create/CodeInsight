#include "bits/stdc++.h"

using namespace std;

void Main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b - a == c - b) {
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
