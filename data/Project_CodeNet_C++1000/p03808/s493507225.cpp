#include<iostream>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
    int64_t N, sum = 0;
    cin >> N;
    int A[N];
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    int64_t oneMove = N * (N + 1) / 2;
    if (sum % oneMove) {
        puts("NO");
        return 0;
    }
    int64_t k = sum / oneMove, cnt = 0;
    rep(i, N) {
        int d = A[(i+1)%N] - A[i] - k;
        if (d % N) {
            puts("NO");
            return 0;
        }
        cnt += abs(d / N);
    }
    puts(cnt == k ? "YES" : "NO");
}