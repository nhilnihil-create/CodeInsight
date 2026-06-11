#include <bits/stdc++.h>

using namespace std;

char s[100005];
int main() {

    int k, t;
    scanf("%d %d", &k, &t);
    int A[10005];
    for (int i = 0; i < t; ++i) {
        scanf("%d", A + i);
    }
    sort(A, A + t);
    reverse(A, A + t);
    int res = A[0] - 1;
    
    for (int i = 1; i < t; ++i) {
        if (res <= 0) break;
        res -= A[i];
    }
    printf("%d\n", res < 0 ? 0 : res);
        

    return 0;
}
