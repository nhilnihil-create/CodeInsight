#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    map<int, int> A;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (A.count(a) == 0) {
            A.insert(make_pair(a, 0));
        }
        A[a] += 1;
    }

    int nSingle = 0;
    int nPair = 0;
    for (auto e : A) {
        if (e.second % 2 == 0) {
            ++nPair;
        }
        else {
            ++nSingle;
        }
    }

    int ans = nSingle;
    if (nPair % 2 == 0) {
        ans += nPair;
    }
    else {
        ans += nPair - 1;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
