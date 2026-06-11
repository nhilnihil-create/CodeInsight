#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, K;
    cin >> N >> K;
    vector<int> l(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> l[i];
    }
    sort(l.begin(), l.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < K; ++i) {
        ans += l[i];
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
