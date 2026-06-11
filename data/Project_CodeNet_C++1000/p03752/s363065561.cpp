#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    long long A[N];
    rep(i, N) cin >> A[i];
    long long ans =  pow(2, 61);
    if (K == 1) {
        printf("0\n");
        return 0;
    }
    for (int bit = 0; bit < (1<<N); bit++) {
        int num = bitset<32>(bit).count();
        if (num != K) continue;
        if (!(bit & (1<<0))) continue;
        long long res = 0;
        long long st_height = A[0];
        for (int a = 1; a < N; a++) {
            if (bit & (1<<a)) {
                if (A[a] > st_height) {
                    st_height = A[a];
                } else {
                    st_height++;
                    res += st_height - A[a];
                }
            } else {
                if (A[a] > st_height) st_height = A[a];
            }
        }
        if (res < ans) ans = res;
    }
    printf("%lld\n", ans);
    return 0;
}
