#include <cstdio>
#define p 1000000007

int c[200002], ni[200002];
int H, W, A, B;

inline long long ksm(long long a, int k)
{
    long long ans = 1;
    while(k)
    {
        if(k & 1)
            ans = ans * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return ans;
}

inline void init()
{
    c[0] = 1;
    ni[0] = 1;
    int maxn = H+W-2;
	for(register int i = 1; i <= maxn; i += 1)
	    c[i] = (long long)c[i-1] * i % p;
	ni[maxn] = ksm(c[maxn], p-2);
	for(register int i = maxn; i; i -= 1)
		ni[i-1] = (long long)ni[i] * i % p;
}

inline long long C(int m, int n)
{
    return (long long)c[m] * ni[n] % p * ni[m-n] % p;
}

int main()
{
    scanf("%d%d%d%d", &H, &W, &A, &B);
    init();
    int AW = A+W-1, HA = H-A-2, AO = A-1, HO = H-A-1;
    long long ans = C(H+W-2, W-1);
    long long rem = 0;
    for(register int i = 1; i <= B; i += 1)
    {
        rem += C(AW-i, AO) * C(HA+i, HO) % p;
        if(rem >= p)
            rem -= p;
    }
    ans = (ans - rem + p) % p;
    printf("%lld", ans);
}