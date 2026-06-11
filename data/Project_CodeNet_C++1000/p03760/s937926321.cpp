#include "bits/stdc++.h"

using namespace std;

void Main() {
    string O, E;
    cin >> O >> E;
    int N = O.size() + E.size();
    string ans = "";
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            ans += O[i / 2];
        }
        else {
            ans += E[i / 2];
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
