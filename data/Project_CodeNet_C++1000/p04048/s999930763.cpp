#include<stdio.h>
long long ans;
void dfs(long long l, long long s) {
    if(l % s == 0) {
        ans += l * 2 - s;
        return;
    }
    ans += l / s * s * 2;
    dfs(s, l % s);
}
int main() {
    long long n, x;
    scanf("%lld%lld", &n, &x);
    ans = n;
    if(x > n - x) dfs(x, n - x);
    else dfs(n - x, x);
    printf("%lld\n", ans);
    return 0;
}