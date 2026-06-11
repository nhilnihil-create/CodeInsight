#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
using namespace std;
using Int = long long;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,f,t) for(int i=f;i<t;i++)
#define P(r) do{for(auto i:r){cout<<i<<' ';}cout<<'\n';}while(0)
int main()
{
    int N; cin >> N;
    vector<Int> A(3*N); REP(i, 3*N) cin >> A[i];
    vector<Int> B(N+1), C(N+1);
    priority_queue<Int, vector<Int>, greater<Int>> Q1(A.begin(), A.begin() + N);
    priority_queue<Int> Q2(A.begin() + 2*N, A.begin() + 3*N);
    B[0] = accumulate(A.begin(), A.begin() + N, (Int)0);
    FOR(i, 1, N+1) {
        Q1.push(A[N+i-1]);
        Int t = Q1.top();
        Q1.pop();
        B[i] = B[i-1] - t + A[N+i-1];
    }
    C[0] = accumulate(A.begin() + 2*N, A.begin() + 3*N, (Int)0);
    FOR(i, 1, N+1) {
        Q2.push(A[2*N-i]);
        Int t = Q2.top();
        Q2.pop();
        C[i] = C[i-1] - t + A[2*N-i];
    }
    FOR(i, 1, N+1) C[i] = min(C[i], C[i-1]);
    Int res = numeric_limits<Int>::min();
    REP(i, N+1) res = max(res, B[i] - C[N-i]);
    cout << res << endl;
    return 0;
}
