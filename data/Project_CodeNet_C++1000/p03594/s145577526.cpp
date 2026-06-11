#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
int n,m,d;
char c[3][3]=
{
    "RY",
    "GB"
};
int main()
{
    read(n),read(m),read(d);
    for(int i=1;i<=n;++i,puts(""))
        for(int j=1;j<=m;++j)
            putchar(c[((i+j+m)/d)&1][((i-j+m)/d)&1]);
    return 0;
}