#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    if (A > B)
        cout << 0 << endl;

    else if (N == 1)
        cout << (A == B ? 1 : 0) << endl;

    else {
        ll Min = A * (N - 2);
        ll Max = B * (N - 2);
        cout << Max - Min + 1 << endl;
    }
}
