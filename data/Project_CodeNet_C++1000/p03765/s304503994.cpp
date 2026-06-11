#include <stdio.h>
#include <cstring>
#include <array>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

constexpr int N = 1e5;
char S[N+10], T[N+10];
std::array<short, N+1> vS, vT;
constexpr short K = 'A' - 1;

int main(void){
    // A -> BB -> AAAA ; ABBAA -> ABBB
    // A -> AAAA -> AAABB -> BB
    // つまり, A = BB = AAAA
    //        B = AA = BBBB   : 3文字 === 空文字列
    // BA -> BBB = 0 : A = 1, B = 2と置いた時ハッシュ値みたいになるのでは？
    scanf("%s%s", S, T);
    int n = strlen(S), m = strlen(T);
    vS[0] = 0; REP(i, n) vS[i+1] = (vS[i] + S[i] - K) % 3;
    vT[0] = 0; REP(i, m) vT[i+1] = (vT[i] + T[i] - K) % 3;
    int q; scanf("%d", &q);
    while(q--){
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d); a--; c--;
        short sss = (vS[b] - vS[a] + 3) % 3;
        short ttt = (vT[d] - vT[c] + 3) % 3;
        puts(sss==ttt ? "YES" : "NO");
    }
    return 0;
}
