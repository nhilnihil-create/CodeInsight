#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int K, T;
    cin >> K >> T;
    vector<int> A(T);
    rep(i, T) cin >> A[i];
    
    sort(A.rbegin(), A.rend());
    if (K & 1) {
        int X = max(0, A[0] - (K + 1) / 2);
        cout << 2 * X << endl;
    } else {
        int X = max(0, A[0] - K / 2);
        if (X == 0) cout << 0 << endl;
        else cout << 1 + 2 * (X - 1) << endl;
    }
    return 0;
}
