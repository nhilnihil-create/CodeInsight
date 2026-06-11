#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;

    int nbConn = 1;
    char prev;
    for (int i = 0; i < S.size(); ++i) {
        if (i == 0) {
            prev = S[i];
            continue;
        }
        char curr = S[i];
        if (prev != curr) {
            ++nbConn;
        }
        prev = curr;
    }
    cout << (nbConn - 1) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
