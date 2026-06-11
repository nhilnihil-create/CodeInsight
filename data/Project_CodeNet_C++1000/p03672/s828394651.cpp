#include "bits/stdc++.h"

using namespace std;

bool isEven(string s) {
    int n = s.size() / 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n + i]) {
            return false;
        }
    }
    return true;
}

void Main() {
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 1; i < N; ++i) {
        if ((N - 1 - i) % 2 == 1) {
            continue;
        }
        string s = S.substr(0, N - 1 - i);
        if (isEven(s)) {
            cout << s.size() << endl;
            return;
        }
    }
    cout << "" << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
