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
    
    vector<vector<int>> like(N);
    rep(i, N) like[A[i] - 1].push_back(i);
    int ans = 0;
    rep(i, N) {
        for (int n : like[i]) {
            if (n == A[i] - 1) ++ans;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
