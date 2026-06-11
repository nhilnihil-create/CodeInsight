// メモリ最小になりたい
#include <array>

constexpr int N = 1e5;
std::array<char, N+1> vS, vT;
constexpr short K = 'A' - 1;

int main(void){
    int i = 0;char c1, c2;
    vS[0] = 0; while((c1 = getchar()) != '\n'){ vS[i+1] = (vS[i] + c1 - K) % 3; i++;}
    i = 0;
    vT[0] = 0; while((c2 = getchar()) != '\n'){ vT[i+1] = (vT[i] + c2 - K) % 3; i++;}
    scanf("%d", &i);
    while(i--){
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d); a--; c--;
        c1 = (vS[b] - vS[a] + 3) % 3;
        c2 = (vT[d] - vT[c] + 3) % 3;
        puts(c1 == c2 ? "YES" : "NO");
    }
    return 0;
}
