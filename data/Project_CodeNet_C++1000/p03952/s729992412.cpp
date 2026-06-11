#include <bits/stdc++.h>
using namespace std;

int ans[200009];
bool chk[200009];

int main() {
    int N, x; scanf("%d%d",&N,&x);
    if(N == 2) {
        if(x == 2) puts("Yes\n1\n2\n3");
        else puts("No");
        return 0;
    }
    if(x == 1 || x == 2*N-1) return !printf("No");
    if(x+2 <= 2*N-1) {
        ans[N] = x;
        ans[N-1] = x-1;
        ans[N-2] = x+1;
        ans[N+1] = x+2;
        chk[x-1] = chk[x] = chk[x+1] = chk[x+2] = 1;
    }
    else if(x-2 >= 1) {
        ans[N] = x;
        ans[N-1] = x+1;
        ans[N-2] = x-1;
        ans[N+1] = x-2;
        chk[x+1] = chk[x] = chk[x-1] = chk[x-2] = 1;
    }
    for(int i=1, j=1; i<=2*N-1; i++) {
        while(chk[j]) ++j;
        if(ans[i] == 0) ans[i] = j++;
    }
    puts("Yes");
    for(int i=1; i<=2*N-1; i++) printf("%d\n",ans[i]);
    return 0;
}
