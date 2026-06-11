#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)1e5 + 4;
long long N, k;
long long arr[NS];
long long sum[NS], hap[NS];

int main(){
    scanf("%lld %lld", &N, &k);
    for(long long i = 1; i <= N; ++i){
        scanf("%lld", arr + i);
        sum[i] = sum[i - 1] + arr[i];
        hap[i] = hap[i - 1] + max(0ll, arr[i]);
    }
    long long ans = 0;
    for(long long i = 1; i + k - 1 <= N; ++i){
        ans = max(ans, hap[N] - hap[i + k - 1] + hap[i - 1] + max(0ll, sum[i + k - 1] - sum[i - 1]));
    }
    printf("%lld\n", ans);
    return 0;
}
