#include<cstdio>
#include<algorithm>
using namespace std;
const static int MOD = 1e9+7;
using ull = unsigned long long;

int main(){
    int N;
    scanf("%d", &N);
    int A[N], B[N];
    for(int i = 0; i < N; ++i){
        scanf("%d", A + i);
        B[i] = abs(i - (N - 1 - i));
    }
    sort(A, A + N);
    sort(B, B + N);
    for(int i = 0; i < N; ++i){
        if(A[i] != B[i]){
            printf("0\n");
            return 0;
        }
    }
    ull answer = 1ULL;
    for(int i = 0; i < N>>1; ++i){
        (answer <<= 1) %= MOD;
    }
    printf("%llu\n", answer);
    return 0;
}