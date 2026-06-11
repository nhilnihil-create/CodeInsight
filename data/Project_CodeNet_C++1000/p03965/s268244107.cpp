#include "bits/stdc++.h"

using namespace std;

void Main() {
    string s;
    cin >> s;
    int ng = 0;
    int np = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'g') {
            ++ng;
        }
        else {
            ++np;
        }
    }

    int ans = s.size() / 2 - np;
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
