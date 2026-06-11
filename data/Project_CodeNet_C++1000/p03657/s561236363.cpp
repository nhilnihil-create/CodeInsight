#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;
    bool possible = false;
    if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) {
        possible = true;
    }
    cout << (possible ? "Possible" : "Impossible") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
