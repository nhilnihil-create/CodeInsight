#include <bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9+7;

int canPass[111111];
int x[111111];

int main(void) {

    int n = 0; scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
    }


    canPass[1] = 0;
    canPass[2] = 1;
    for (int i = 3; i <= n; ++i) {
        if (x[i-1] >= canPass[i-1]*2+1) {
            canPass[i] = canPass[i-1]+1;
        } else {
            canPass[i] = canPass[i-1];
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d ", canPass[i]);

    // }
    // puts("");
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans = (long long) ans * (canPass[i]+1) % mod;
    }
    printf("%d\n", ans);

    return 0;
}