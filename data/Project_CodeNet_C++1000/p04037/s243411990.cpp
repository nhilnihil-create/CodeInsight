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

const int N = 100000 + 5;

int n , A[N];

#ifdef Lin1043
namespace TEST
{
    const int M = 200 + 5;

    int f[M][M] , g[M][M];

    int solve(int x , int y)
    {
        if(g[x][y])
            return 0;
        if(f[x][y] != -1)
            return f[x][y];
        int now = 0;
        if(solve(x + 1 , y) == 0)
            now = 1;
        if(solve(x , y + 1) == 0)
            now = 1;
        return f[x][y] = now;
    }
}
#endif 

int comp(int x , int y)
{
    return x > y;
}

int main()
{
    read(n);
    rep(i , 1 , n) read(A[i]);
    sort(A + 1 , A + 1 + n , comp);
#ifdef Lin1043
    rep(i , 1 , n)
        TEST::g[i][A[i]] = 1;
    memset(TEST::f , -1 , sizeof TEST::f);
    TEST::solve(1 , 0);
    cout << TEST::f[1][0] << endl;
#endif
    rep(i , 1 , n) if(i + 1 > A[i + 1])
    {
        int Ans = 0;
        rep(j , i + 1 , n)
        {
            if(A[j] != i) break;
            Ans ^= 1;
        }
        Ans |= (A[i] - i) % 2;
        if(Ans)
            puts("First");
        else
            puts("Second");
        break ;
    }
    return 0;
}

