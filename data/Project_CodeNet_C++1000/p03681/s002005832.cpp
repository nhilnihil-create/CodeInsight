#include <bits/stdc++.h>
using namespace std;

#define min(a,b) (((a) > (b)) ? (b) : (a))
#define max(a,b) (((a) < (b)) ? (b) : (a))
#define abs(a) (((a) < 0) ? (-(a)) : (a))

constexpr int64_t MOD = 1000000007;
int64_t fact(int64_t n) {
    int64_t ret = 1;
    for(;n>1;n--) {
//printf("n(%ld):%ld\n", n, ret);
        ret = ((ret * n) % MOD);
    }

    return ret % MOD;
}

int main(void) {
    int64_t N,M; 
    int64_t result = 0;
    
    cin >> N >> M;
    if(N == M) {
        result = fact(N);
        result = (result * result) % MOD;
        result = (result * 2) % MOD;
    } else if(abs(N-M) == 1) {
        result = fact(min(N,M));
        result = (result * result ) % MOD;
        result = (result * max(N,M)) % MOD;
    } else {
        result = 0;
    }

    cout << result << "\n";
    return 0;
}
