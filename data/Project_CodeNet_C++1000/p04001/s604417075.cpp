#include <bits/stdc++.h>
using namespace std;

// utility
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, begin, end) for (int i = (begin); i < (end); i++)
#define REP(i, n) FOR(i, 0, n)
#define rer(i, l, u) for (int(i) = (int)(l); (i) <= (int)(u); ++(i))
#define reu(i, l, u) for (int(i) = (int)(l); (i) < (int)(u); ++(i))

#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)

#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n", (x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n", (x) ? "Yes" : "No")
#define F first
#define S second


char s[11];


signed main()
{
    ios_base::sync_with_stdio(false);
    // ⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎
// 前から順に見ていって、「数字があるたびに現在の値を 10 倍して今書いてある数字だけ足す」
//「‘+(’ が出てきたら現在の値が ‘+(’ の直前の整数に等しいので、それを答えに足す」
//「最後は ‘+(’ が登場せずに数式が終わるので、そこは別に足す」
    int n, i, j;
    long long ans = 0;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    if (n == 1) {
        printf("%s\n", s);
        
        return 0;
    }
    
    for (i = 0; i < (1 << (n - 1)); i++) {
        long long x = 0;
        
        for (j = 0; j < n; j++) {
            x *= 10;
            x += s[j] - '0';
            
            if ((i >> j) & 1) {
                ans += x;
                x = 0;
            }
        }
        
        ans += x;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
