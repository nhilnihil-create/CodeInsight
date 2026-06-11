#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define P pair<int,int>
const LL inf = 0x3f3f3f3f;
const LL mod = 1e9+7;
const LL N = 1e5+10;
template <typename tp> inline void read(tp &x)
{
    x=0;char c=getchar();int f=0;
    for(;c>'9'||c<'0';f|=(c=='-'),c=getchar());
    for(;c<='9'&&c>='0';x=(x<<3)+(x<<1)+c-'0',c=getchar());
    if(f) x=-x;
}
int n,x[N],zz,mm;
bool cmp(int a,int b){return a>b;}
int main()
{
    read(n);
    for(int i=1;i<=n;i++) read(x[i]);
    sort(x+1,x+n+1,cmp);
    for(int i=0;i<=n;i++) if(x[i+2]<=i+1) {mm=i;break;}
    for(int i=1;i<=n;i++) if(x[i]>mm) zz=i;
    if((x[mm+1]-mm)%2==1&&(zz-mm)%2==1) puts("Second");
    else puts("First");
    return 0;
}