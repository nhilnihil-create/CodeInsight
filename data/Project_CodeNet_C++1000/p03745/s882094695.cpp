#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    int ans = 1;
    int joutai = 0;
    REP(i, N) {
        if (joutai == 1 && A[i - 1] > A[i]) {
            ++ans;
            joutai = 0;
            continue;
        }
        if (joutai == 2 && A[i - 1] < A[i]) {
            ++ans;
            joutai = 0;
            continue;
        }
        if (A[i - 1] < A[i]) joutai = 1;
        if (A[i - 1] > A[i]) joutai = 2;
    }
    cout << ans << endl;
    return 0;
}
