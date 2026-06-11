#include<bits/stdc++.h>
using ll = int_fast64_t;
#define REP(i,b,e) for(ll i=b; i<e; i++)

int main(){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        bool ok = false;
        REP(i, 0, n+1) REP(j, 0, m+1) {
            if((n-i)*(m-j)+i*j==k) ok = true;
        }
        if(ok) puts("Yes");
        else puts("No");
        return 0;
}