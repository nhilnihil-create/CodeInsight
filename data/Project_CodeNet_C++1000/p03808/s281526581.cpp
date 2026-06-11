#include <bits/stdc++.h>
using namespace std;
using Int = long long;
bool solve(const vector<int> &A)
{
    Int N = A.size();
    Int sum = accumulate(begin(A), end(A), 0LL);
    Int one = N * (N+1) / 2;
    if (sum % one) return false;
    Int cnt = sum / one;
    vector<int> B(N);
    B[0] = A[0] - A[N-1];
    for (int i = 1; i < N; i++) B[i] = A[i] - A[i-1];
    Int t = 0;
    for (auto b : B) {
        b -= cnt;
        if (b % -N) return false;
        if (b / -N < 0) return false;
        t += b / -N;
    }
    return t == cnt;
}
int main()
{
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    cout << (solve(A) ? "YES" : "NO") << endl;
    return 0;
}