#include <iostream>
#include <algorithm>
using namespace std;
const int N = 102;
int a[N], n, c[N];

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]); c[a[i]] ++;
    }

    sort(a+1,a+1+n);
    if (a[n] == 1) {
        return !printf("%s\n", n==2 ? "Possible" : "Impossible");
    }
    if (a[n-1] != a[n]) {
        return !printf("Impossible\n");
    }
    for(int i=1;i<=a[n]+1;i++) {
        //printf("# %d\n", max(a[n]+1-i, i-1));
        c[max(a[n]+1-i, i-1)] --;
        if(c[max(a[n]+1-i, i-1)] < 0) return !printf("Impossible\n");
    }

    for(int i=1;i<=a[n];i++){
        //printf("i=%d\n", i);
        if(c[i] && i<=(a[n]+1)/2) return !printf("Impossible\n");
    }
    printf("Possible\n");
}
/*
# # # # # #
*/
