#include "bits/stdc++.h"

using namespace std;

void Main() {
    string N;
    cin >> N;

    bool has9 = false;
    if (N[0] == '9' || N[1] == '9') {
        has9 = true;
    }
    cout << (has9 ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
