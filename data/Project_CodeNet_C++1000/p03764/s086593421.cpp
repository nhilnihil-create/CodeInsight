#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int mod = 1e9 + 7;

int sum(vector<int> &A) {
    int N = A.size();
    int ret = 0;
    for(int i = 0; i < N - 1; i++) {
        long long plus = (i + 1LL) * (N - 1 - i) % mod;
        plus = plus * (A[i + 1] - A[i]) % mod;
        ret = (ret + plus) % mod;
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    cout << (1LL * sum(A) * sum(B)) % mod << endl; 
    return 0;
}