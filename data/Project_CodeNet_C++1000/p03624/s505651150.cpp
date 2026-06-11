#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;
    set<char> alphabet;
    for (int i = 0; i < S.size(); ++i) {
        alphabet.insert(S[i]);
    }
    for (int i = 0; i < 26; ++i) {
        char x = 'a' + i;
        if (alphabet.count(x) == 0) {
            cout << x << endl;
            return;
        }
    }
    cout << "None" << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
