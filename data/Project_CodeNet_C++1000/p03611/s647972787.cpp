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
    int ans = 0;
    for (int x = 0; x <= 100000; ++x) {
        int mid = A.count(x) == 0 ? 0 : A[x];
        int p = A.count(x + 1) == 0 ? 0 : A[x + 1];
        int m = A.count(x - 1) == 0 ? 0 : A[x - 1];
        ans = max(ans, mid + p + m);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
