#include <bits/stdc++.h>

using namespace std;

#ifdef Lin1043
    #define DEBUG(msg, ...) printf("(%s #%d) " msg, __FUNCTION__, __LINE__, __VA_ARGS__)
    #define massert(...) assert(...)
#else
    #define DEBUG(...)
    #define massert(...)
#endif

#define rep(i , l , r) for(int i = (l) , ___ = (r) ; i <= ___ ; ++i )
#define per(i , r , l) for(int i = (r) , ___ = (l) ; i >= ___ ; --i )

struct iopener
{
    iopener()
    {
#ifdef Lin1043
        freopen("./in" , "r" , stdin);
#endif
    }
} iop;

typedef long long LL;

template<typename T>inline bool chkmin(T &x , const T &y) { return x > y ? (x = y , 1) : 0; }
template<typename T>inline bool chkmax(T &x , const T &y) { return x < y ? (x = y , 1) : 0; }

template<typename T>inline T read(T &f)
{
    f = 0; int x = 1 ; char c = getchar();
    while(!isdigit(c)) x = (c == '-' ? -1 : 1) , c = getchar();
    while(isdigit(c)) (f *= 10) += c & 15 , c = getchar();
    return f = x * f;
}

const int N = 2000 + 5 , L = 4000000;

int n , k ;
LL fac[L+10] , inv[L+10];

const int KCZ = 1e9 + 7;

LL mp(LL x , LL y = KCZ - 2)
{
    LL res = 1;
    while(y)
    {
        if(y & 1)
            res = res * x % KCZ;
        x = x * x % KCZ;
        y >>= 1;
    }
    return res;
}

void init()
{
    fac[0] = 1;
    rep(i , 1 , L) fac[i] = fac[i - 1] * i % KCZ;
    inv[L] = mp(fac[L]);
    per(i , L - 1 , 1) inv[i] = inv[i + 1] * (i + 1) % KCZ;
    inv[0] = 1;
}

LL C(int n , int m)
{
    if(n < m) return 0;
    return fac[n] * inv[m] % KCZ * inv[n - m] % KCZ;
}

LL f[N][N];

void add(LL &x , const LL &y)
{
    x += y; if(x >= KCZ) x -= KCZ;
}

int main()
{
    read(n) , read(k) , init();
    if(k == 1)
        return puts("1") , 0;
    f[0][0] = 1;
    rep(i , 1 , n)
    {
        per(j , i , 0)
        {
            f[i][j] = f[i][j + 1]; 
            if(j >= 1)
                add(f[i][j] , f[i - 1][j - 1] * C(i * k - j - 1 , k - 2) % KCZ);
        }
    }
    printf("%lld\n" , f[n][0] * fac[n] % KCZ);
    return 0;
}

