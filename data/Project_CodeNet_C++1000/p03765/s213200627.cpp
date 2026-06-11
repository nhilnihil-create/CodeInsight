#include <bits/stdc++.h>
using namespace std;

int Q;
char S[101010], T[101010];
int SA[101010], TA[101010];

int main(){
    int s, e, l, r;
    scanf("%s", S+1);
    scanf("%s", T+1);
    for (int i=1; S[i]; i++){
        if (S[i] == 'A') SA[i]++;
        SA[i] += SA[i-1];
    }
    for (int i=1; T[i]; i++){
        if (T[i] == 'A') TA[i]++;
        TA[i] += TA[i-1];
    }
    scanf("%d", &Q);
    while (Q--){
        scanf("%d %d %d %d", &s, &e, &l, &r);
        int x = (2*(SA[e] - SA[s-1]) - (e-s+1) + 3000000)%3;
        int y = (2*(TA[r] - TA[l-1]) - (r-l+1) + 3000000)%3;
        puts((x == y) ? "YES" : "NO");
    }
    return 0;
}
