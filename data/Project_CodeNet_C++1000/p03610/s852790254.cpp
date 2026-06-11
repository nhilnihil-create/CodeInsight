#include "bits/stdc++.h"

using namespace std;

void Main() {
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            ans += s.substr(i, 1);
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
