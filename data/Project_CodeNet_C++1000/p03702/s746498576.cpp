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

long long n,A,B;
long long a[ MAXN ];
long long add;

bool check(long long lim){
long long cnt=0;
for (long long i=1;i<=n;i++)
    {
        long long tmp=max(0ll,a[i]-lim*B);
        cnt+=(tmp+add-1)/add;
        //printf("%d %d\n",tmp,cnt);
    }
return cnt<=lim;
}


int main(){
    read(n);read(A);read(B);
    add=A-B;
    for(long long i=1;i<=n;i++)
        read(a[i]);
    sort(a+1,a+n+1);
    long long l=1,r=a[n];
    long long ans=0;
    while (l<=r)
        {
            long long mid=(l+r)/2;
            if( check( mid ) )
                {
                    ans=mid;
                    r=mid-1;
                }
            else
                l=mid+1;
        }
    cout<<ans<<endl;
    return 0;
}
