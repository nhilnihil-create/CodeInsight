#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;
    set<char> s;
    for (int i = 0; i < S.size(); ++i) {
        s.insert(S[i]);
    }
    cout << (s.size() == S.size() ? "yes" : "no") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
