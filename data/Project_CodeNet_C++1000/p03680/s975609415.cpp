#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        a[i] -= 1;
    }

    set<int> lighten;
    int ans = -1;
    int l = 0;
    for (int i = 0; i < N; ++i) {
        l = a[l];
        if (l == 1) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
