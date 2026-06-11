#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL<<60;
int N;
long long X;
vector<long long> A;

long long solve() {
    long long res = INF;
    for (int i = 0; i < N; ++i) A.push_back(A[i]);
    vector<long long> bmin(N, INF);
    for (int k = 0; k < N; ++k) {
        long long tmp = 0;
        for (int i = 0; i < N; ++i) {
            chmin(bmin[i], A[i+k]);
            tmp += bmin[i];
        }
        chmin(res, tmp + X*k);
    }
    return res;
}

int main() {
    while (cin >> N >> X) {
        A.resize(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << solve() << endl;
    }
}