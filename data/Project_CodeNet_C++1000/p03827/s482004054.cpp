#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int x = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'I') {
            ++x;
        }
        else {
            --x;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
