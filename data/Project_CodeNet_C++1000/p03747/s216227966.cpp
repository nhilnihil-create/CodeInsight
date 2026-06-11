#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) fprintf(stderr,__VA_ARGS__)

#define rep(i , l , r) for(int i = (l) , ___ = (r) ; i <= ___ ; ++i )
#define per(i , r , l) for(int i = (r) , ___ = (l) ; i >= ___ ; --i )

// using LL = long long;
// using uLL = unsigned long long;
typedef long long LL;
typedef unsigned long long uLL;

const int Mod = 998244353; 

template<typename T>inline bool chkmin(T &x , const T &y) { return x > y ? (x = y , 1) : 0; }
template<typename T>inline bool chkmax(T &x , const T &y) { return x < y ? (x = y , 1) : 0; }

template<typename T>inline T sq(const T &x) { return x * x; }
template<typename T>inline T add(T x , const T &y) { x += y; return x > Mod ? x - Mod : x; }
template<typename T>inline T sub(T x , const T &y) { x -= y; return x < 0 ? x + Mod : x;}
template<typename T>inline T mul(const T &x , const T &y) { return 1ll * x * y % Mod; }

template<typename T>inline T read(T &f)
{
    f = 0; int x = 1 ; char c = getchar();
    while(!isdigit(c)) x = (c == '-' ? -1 : 1) , c = getchar();
    while(isdigit(c)) (f *= 10) += c & 15 , c = getchar();
    return f = x * f;
}
// template<typename T , typename ... Args>inline void read(T &x , Args&& ... y) { read(x) , read(y...); }

const int N = 100000 + 5;

int n , L , T , A[N] , W[N] , v[N];

int main()
{
    read(n) , read(L) , read(T);
    rep(i , 0 , n-1) read(A[i]) , read(W[i]);
    rep(i , 0 , n-1)
    {
        if(W[i] == 1) v[i] = (A[i] + T) % L;
        if(W[i] == 2) v[i] = (A[i] - T) % L , v[i] = (v[i] + L) % L;
    }
    int x = v[0] , p;
    sort(v , v + n);
    if(W[0] == 1)
    {
        rep(i , 0 , n-1) if(v[i] == x)
        {
            p = i ; break ;
        }
    }
    else
    {
        per(i , n-1 , 0) if(v[i] == x)
        {
            p = i ; break ;
        }
    }
    int R1 = 0 , R2 = 0;
    rep(i , 1 , n-1)
    {
        if(W[i] == W[0]) continue ;
        R1 += 2;
        int dis = A[i] - A[0];
        if(W[0] == 2) dis = L - dis;
        if(dis < T % L * 2) R2++;
        if(dis < T % L * 2 - L) R2++;
    }
    int t = R1 * (T / L) + R2; t %= n;
    if(W[0] == 2) t = (n - t) % n;
    rep(i , 0 , n-1) printf("%d\n" , v[(i + p - t + n) % n]);
    return 0;
}
