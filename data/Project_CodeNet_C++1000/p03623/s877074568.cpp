#include "bits/stdc++.h"

using namespace std;

void Main() {
    int x, a, b;
    cin >> x >> a >> b;
    cout << (abs(x - a) < abs(x - b) ? "A" : "B") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
