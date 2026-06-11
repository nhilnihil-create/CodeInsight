#include <bits/stdc++.h>

using namespace std;

int n, m, a[105], ans = 0, cnt;

void display(int l, int r) { for(int i = l; i <= r; i++) printf("%d ", a[i]); printf("\n"); }

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a[i];
    if(n == 1) return printf("1\n1\n1\n"), 0;
    if(m == 1) return printf("%d \n2 \n%d 1\n", n, n - 1), 0;
    sort(a, a + m, [](int x, int y) { return (x & 1) > (y & 1); });
    if(a[2] & 1) return printf("Impossible\n"), 0;
    cnt = (a[0] & 1) + (a[1] & 1);
    a[m] = a[0];
    if(cnt == 2) { 
        if(m == 2) {
            printf("%d %d\n", a[0], a[1]);
            if(a[1] == 1) {
                printf("1\n");
                printf("%d\n", a[0] + 1);
            }
            else {
                printf("2\n");
                printf("%d %d\n", a[0] + 1, a[1] - 1);
            }
            return 0;
        }
        sort(a + 2, a + m);
        if(1) {
            display(1, m);
            if(a[1] == 1) {
                printf("%d \n", m - 1);
                for(int i = 2; i < m; i++) printf("%d ", a[i]); 
                printf("%d\n", a[m] + 1);   
            }
            else {
                printf("%d \n", m);
                printf("%d ", a[1] - 1);
                for(int i = 2; i < m; i++) printf("%d ", a[i]); 
                printf("%d\n", a[m] + 1);
            }
        }
    }
    else if(cnt == 1) {
        sort(a + 1, a + m);
        if(a[m - 1] - 2 == 0) {
            display(0, m - 1);
            m--;
            printf("%d \n", m + 1);
            printf("%d ", a[0] + 1);
            for(int i = 1; i < m; i++) printf("2 ");
            printf("1\n");
        }
        else {
            display(0, m - 1);
            m--;
            printf("%d \n", m + 2);
            printf("%d ", a[0] + 1);
            for(int i = 1; i < m; i++) printf("%d ", a[i]); 
            printf("1 ");
            printf("%d\n", a[m] - 2);
        }
    }
    else {
        sort(a + 1, a + m + 1);
        if(a[m] - 2 == 0) {
            display(1, m);
            printf("%d \n", m + 1);
            printf("1 ");
            for(int i = 1; i < m; i++) printf("2 "); 
            printf("1\n");
        }
        else {
            display(1, m);
            printf("%d \n", m + 2);
            printf("1 ");
            for(int i = 1; i < m; i++) printf("%d ", a[i]); 
            printf("1 ");
            printf("%d\n", a[m] - 2);
        }
    }
    return 0;
}