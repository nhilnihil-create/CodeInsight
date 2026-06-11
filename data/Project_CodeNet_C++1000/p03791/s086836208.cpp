#include<cstdio>
using namespace std;
const long long MOD = 1000000007;

int main() {
    int n, now = 0, k = 0;
    long long ans = 1;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        int t;
        scanf("%d", &t);
        now++;
        ans = (ans * now) % MOD;
        if(t < 2 * i + 1 - 2 * k) now--, k++;
    }
    printf("%lld\n", ans);
    return 0;
}
