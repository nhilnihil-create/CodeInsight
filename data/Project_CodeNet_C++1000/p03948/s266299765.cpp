#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int a, m, p, ans;
    p = -1;
    ans = 0;
    m = 1000000005;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        m = min(m, a);
        if (a - m == p) {
          ans++;
        } else if (a - m > p) {
            p = a - m;
            ans = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}