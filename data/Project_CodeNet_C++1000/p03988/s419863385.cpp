#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int nd[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    if (a[n - 1] != a[n - 2] || (n > 2 && a[n - 1] == 1))
        printf("Impossible\n");
    else {
        for (int i = 1; i < a[n - 1]; i++)
            nd[max(i, a[n - 1] - i)]++;
        int lim = (a[n - 1] + 1) / 2;
        int spec = 0;
        for (int i = 0; i < n - 2; i++)
            if (a[i] < lim) {
                printf("Impossible\n"); return 0;
            } else nd[a[i]]--;
        for (int i = 0; i < a[n - 1]; i++)
            if (nd[i] > 0) {
                printf("Impossible\n"); return 0;
            }
        if (nd[(a[n - 1] + 1) / 2] != 0) {
            printf("Impossible\n"); return 0;
        }
        printf("Possible\n");
    }
    return 0;
}
