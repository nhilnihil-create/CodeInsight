#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int nodd = 0;
    int n4 = 0;
    int n2 = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] % 2 == 1) {
            ++nodd;
            continue;
        }
        if (a[i] % 4 == 0) {
            ++n4;
            continue;
        }
        ++n2;
    }

    bool ok = false;
    if (n2 == 0) {
        if (nodd - 1 <= n4) {
            ok = true;
        }
        else {
            ok = false;
        }
    }
    else {
        if (nodd <= n4) {
            ok = true;
        }
        else {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
