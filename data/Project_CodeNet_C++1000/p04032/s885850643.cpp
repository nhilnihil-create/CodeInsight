#include "bits/stdc++.h"

using namespace std;

void Main() {
    string s;
    cin >> s;
    int N = s.size();

    // pattern "aa"
    for (int i = 1; i < N; ++i) {
        if (s[i - 1] == s[i]) {
            cout << i << " " << i + 1 << endl;
            return;
        }
    }
    for (int i = 2; i < N; ++i) {
        if (s[i - 2] == s[i]) {
            cout << i - 1 << " " << i + 1 << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
