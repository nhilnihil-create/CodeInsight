#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll a[maxn];

int main() {
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), sum += a[i];
    }
    if (sum % (1LL * n * (n + 1) / 2)) {
        printf("NO\n"), exit(0);
    }
    sum /= (1LL * n * (n + 1) / 2);
    long long all = 0;
    for (int i = 1; i <= n; i++) {
        int j = i == 1 ? n : i - 1;
        all += (a[j] + sum - a[i]) / n;
        if (a[j] + sum - a[i] < 0) printf("NO\n"), exit(0);
    }
    printf("%s\n", sum == all ? "YES" : "NO");
    return 0;
}