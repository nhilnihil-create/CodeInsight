#include <bits/stdc++.h>

using namespace std;

int n, a[201], ans;

int main() {
    scanf("%d", &n); n <<= 1; 
    for(int i = 1;i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n; i += 2)
        ans += a[i];
    printf("%d\n", ans);
    return 0;
}