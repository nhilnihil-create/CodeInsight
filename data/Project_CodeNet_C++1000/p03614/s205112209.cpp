#include <iostream>
using namespace std;
const int N = 100000 + 10;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }

    int ans = 0, cnt = 0;
    a[n+1] = -1;
    for (int i = 1; i <= n+1; i ++) {
        if (a[i] != i) {
            ans += (cnt + 1) / 2;
            cnt = 0;
        } else {
            cnt ++;
        }
    }
    printf("%d\n", ans);
}