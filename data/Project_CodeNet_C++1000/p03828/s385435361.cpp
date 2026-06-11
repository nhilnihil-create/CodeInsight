#include <bits/stdc++.h>
using namespace std;

#define N 1001
#define M (long long)(1e9+7)

bool isPrime[N];
void eratos(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(size_t i = 2; i < N; i++) 
            if(isPrime[i]) 
                for (size_t j = 2; i*j < N; j++) 
                    isPrime[i*j] = 0;
    return;
}

long long dp[N];

int main() {
    eratos();
    int pqr[N] = {0};
    int n;
    long ans = 1;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        /* 素因数分解 */
        int num = i;
        for (int j = 0; num != 1; j++) {
            if(isPrime[j]) {
                while(num % j == 0) {
                    num /= j;
                    pqr[j]++;
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (pqr[i] != 0) {
            ans = ans * (pqr[i] + 1) % M;
        }
    }
    cout << ans << endl;
}