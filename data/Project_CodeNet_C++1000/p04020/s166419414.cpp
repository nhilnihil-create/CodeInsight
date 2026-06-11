#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N + 2, 0);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    
    vector<int> B, C;
    for (int i = 1; i <= N; ++i) {
        if (A[i - 1] == 0 && A[i] != 0) B.push_back(i);
        if (A[i + 1] == 0 && A[i] != 0) C.push_back(i);
    }
    
    int sum = 0;
    for (int i = 0; i < B.size(); ++i) {
        int cnt = 0;
        for (int j = B[i]; j <= C[i]; ++j) cnt += A[j];
        sum += cnt / 2;
    }
    cout << sum << endl;
    return 0;
}
