#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXD = 10;

int N;
int pow10[MAXD];

inline bool query(int64 n)
{
    static char r[20];
    printf("? %lld\n", n); fflush(stdout);
    scanf("%s", r);
    return r[0] == 'Y';
    /*sprintf(r, "%lld", n);
    static char s[20];
    sprintf(s, "%d", N);
    bool result = ((strcmp(r, s) <= 0) == (n <= N));
    static int ct = 0;
    printf("%d > ", ++ct);
    puts(result ? "Y" : "N");
    return result;*/
}

bool result[MAXD];

int main()
{
    //scanf("%d", &N);

    pow10[0] = 1;
    for (int i = 0; i < MAXD - 1; ++i)
        pow10[i + 1] = pow10[i] * 10;

    for (int i = 0; i < MAXD; ++i)
        result[i] = query(pow10[i]);

    // Corner cases
    if (result[MAXD - 1] == true) {
        for (int i = 0; i < MAXD; ++i)
            if (query(2 * pow10[i])) { printf("! %d\n", pow10[i]); break; }
    } else {
        int dg;
        for (dg = 0; result[dg]; ++dg) ;
        int64 accum = 0;
        for (int i = 0; i < dg - 1; ++i) {
            int lo = 0, hi = 10, mid;
            while (lo < hi - 1) {
                mid = (lo + hi) >> 1;
                if (query(accum * 10 + mid)) lo = mid; else hi = mid;
            }
            accum = accum * 10 + lo;
        }
        for (int j = (dg == 1 ? 1 : 0); j <= 9; ++j)
            if (query(accum * 100 + j * 10)) {
                printf("! %lld\n", accum * 10 + j); break;
            }
    }

    return 0;
}
