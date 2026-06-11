#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

typedef long long LL;

const int M = 1000000007;

int N;
int a[131072];
int ans;
int count;

int main() {
    scanf("%d", &N);
    ans = 1;
    count = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", a + i);
        if (count * 2 + 1 > a[i]) {
            ans = (LL)ans * (count + 1) % M;
        } else {
            count ++;
        }
    }
    for (int i = 1; i <= count; ++i)
        ans = (LL)ans * i % M;
    printf("%d\n", ans);
    return 0;
}