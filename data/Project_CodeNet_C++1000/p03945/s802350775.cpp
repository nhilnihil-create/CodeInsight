#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;

    int N = S.size();
    char curr = S[0];
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if (curr != S[i]) {
            ++ans;
            curr = S[i];
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
