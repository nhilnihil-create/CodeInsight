#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 100005
#define eps 1e-12
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T> void read(T &res)
{
    res=0;
    T f=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    res*=f;
}
template<class T>
void out(T x)
{
    if(x<0){x=-x;putchar('-');}
    if(x>=10)
    {
        out(x/10);
    }
    putchar('0'+x%10);
}
bool Query(int64 t) {
    putchar('?');space;out(t);enter;fflush(stdout);
    char s[5];scanf("%s",s);
    return s[0] == 'Y';
}
void Solve(){
    int64 v=1;
    bool f=0;
    for(int i=1;i<=10;++i)
    {
        if(!Query(v)){f=1;v/=10;break;}
        v*=10;
    }
    if(!f){
        v = 1;
        for(int i= 1;i<=10;++i)
        {
            if(Query(v*10-1)){putchar('!');space;out(v);enter;return;}
            v*=10;
        }
    }
    int64 L=v,R=min(v*10-1,(int64)1e9);
    while(L<R)
    {
        int64 mid=(L+R+1)>>1;
        if(!Query(mid*10))L=mid;
        else R=mid-1;
    }
    putchar('!');
    space;
    out(L + 1);
    enter;
}
int main()
{
    Solve();
    return 0;
}
