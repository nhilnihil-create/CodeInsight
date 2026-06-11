#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, N) cin >> A[i];
    
    set<long long> B;
    vector<long long> S;
    rep(i, N) {
        if (B.count(A[i])) {
            S.push_back(A[i]);
            B.erase(A[i]);
        } else {
            B.insert(A[i]);
        }
    }
    
    if (S.size() < 2) {
        cout << 0 << endl;
    } else {
        sort(S.rbegin(), S.rend());
        cout << S[0] * S[1] << endl;
    }
    return 0;
}
