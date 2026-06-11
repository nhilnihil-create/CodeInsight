#include<bits/stdc++.h>

using namespace std;
inline void read(long long &x) {
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}
inline void write(long long x) {
    static const long long maxlen = 100;
    static char s[maxlen];
    if (x < 0) {   putchar('-'); x = -x;}
    if (!x) { putchar('0'); return; }
    long long len = 0; for (; x; x /= 10) s[len++] = x % 10 + '0';
    for (long long i = len - 1; i >= 0; --i) putchar(s[i]);
}

inline void read(int &x){
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}

const long long MAXN =1001000;

long long n;
long long a[ MAXN ];
long long f[ MAXN ];
long long g[ MAXN ];

priority_queue<long long,vector<long long>,greater<long long> > Q;

priority_queue<long long,vector<long long>,less<long long> > P;

int main(){
    read(n);
    for (long long i=1;i<=3*n;i++)
        read(a[i]);

    for (long long i=1;i<=n;i++)
    {
        Q.push(a[i]);
        f[n]+=a[i];
    }

    for (long long i=n+1;i<=n*2;i++)
        if ( a[i]>Q.top() )
            {
                f[i]=f[i-1]+a[i]-Q.top();
                Q.pop();
                Q.push(a[i]);
            }
        else
            f[i]=f[i-1];

    for (long long i=2*n+1;i<=3*n;i++)
    {
        P.push(a[i]);
        g[2*n+1]+=a[i];
    }

    for (long long i=2*n;i>=n+1;i--)
        if ( a[i]<P.top() )
            {
                g[i]=g[i+1]+a[i]-P.top();
                P.pop();
                P.push(a[i]);
            }
        else
            g[i]=g[i+1];
    long long ans=-1e15;
    for (long long i=n;i<=2*n;i++)
        ans=max(ans,f[i]-g[i+1]);
    cout<<ans<<endl;
    return 0;
}
