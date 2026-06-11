#include "bits/stdc++.h"

using namespace std;

void Main() {
    string N;
    cin >> N;
    bool reversible = (N[0] == N[2]);

    cout << (reversible ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
