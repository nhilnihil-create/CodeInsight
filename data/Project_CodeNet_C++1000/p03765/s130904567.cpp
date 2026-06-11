#include <stdio.h>

constexpr int N = 1e5;
char vS[N+3], vT[N+3];
constexpr short K = 'A' - 1;

int main(void){
    int i, q;char c1, c2;
    scanf("%s%s", vS+1, vT+1);
    vS[0] = 0; i = 1; while(vS[i] != '\0') {(vS[i] += vS[i-1] - K) %= 3; i++;}
    vT[0] = 0; i = 1; while(vT[i] != '\0') {(vT[i] += vT[i-1] - K) %= 3; i++;}
    scanf("%d", &q);
    while(q--){
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d); a--; c--;
        c1 = (vS[b] - vS[a] + 3) % 3;
        c2 = (vT[d] - vT[c] + 3) % 3;
        puts(c1 == c2 ? "YES" : "NO");
    }
    return 0;
}
