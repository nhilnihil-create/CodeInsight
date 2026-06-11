#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], b[100005], cnt = 0;
int pla1, pla2;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &a[i]);
        if (a[i] & 1) {
            cnt ++;
            if (pla1) pla2 = i;
            else pla1 = i;
        }
    }
    if (m == 1) {
        printf("%d\n", a[1]);
        if (a[1] == 1) {
            printf("1\n1");
            return 0;
        }
        printf("2\n");
        printf("%d 1\n", a[1] - 1);
        return 0;
    }
    if (cnt > 2) {
        puts("Impossible"); return 0;
    }
    if (cnt >= 1) swap(a[1], a[pla1]);
    if (cnt == 2) swap(a[m], a[pla2]);
    for (int i = 1; i <= m; i ++) printf("%d ", a[i]);
    if (a[1] == 1) m --;
    printf("\n%d\n", m);
    if (a[1] == 1) m ++;
    if (a[1] != 1) printf("%d ", a[1] - 1);
    for (int i = 2; i < m; i ++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[m] + 1);
    return 0;
}
