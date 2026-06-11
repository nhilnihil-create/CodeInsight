#include <bits/stdc++.h>
using namespace std;

int A[100005];
int B[100005];

int main(void){
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    long long ans = 0;
    int allowed_bits = K;
    for (int i = 0; i < N; i++) {
        if (((allowed_bits | A[i]) ^ allowed_bits) == 0) ans += B[i];
    }
    for (int i = 0; i < 30; i++) {
        if (((1 << i) & K) == 0) continue;
        allowed_bits = (K - (1 << i)) | ((1 << i) - 1);
        
        long long sum = 0;
        for (int j = 0; j < N; j++) {
            if (((allowed_bits | A[j]) ^ allowed_bits) == 0) sum += B[j];
        }
        ans = max(sum, ans);
    }
    cout << ans << endl;
}
