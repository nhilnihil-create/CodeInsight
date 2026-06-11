#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
inline int read(){int tot=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')tot=-1,c=getchar();
int sum=0;while(c<='9'&&c>='0')sum=sum*10+c-'0',c=getchar();return sum*tot;}
void wr(int x){if(x<0){putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
void wrn(int x){wr(x);putchar('\n');}
struct arr{
    int sum,id;
}a[200005];
bool cmp(arr a,arr b){
    if(a.sum==b.sum)return a.id<b.id;
    return a.sum>b.sum;
}
int ans[200005];
signed main()
{
    int n=read();
    for(int i=1;i<=n;i++)a[i].sum=read(),a[i].id=i;
    int f=1,s=2;
    sort(a+1,a+1+n,cmp);
    while(s<=n){
        while(a[s].sum==a[s-1].sum)s++;
        ans[a[f].id]+=(s-1)*(a[f].sum-a[s].sum);
        if(a[s].id<a[f].id)f=s;
        else a[f].sum=a[s].sum;
        s++;
    }
    ans[a[f].id]+=n*a[f].sum;
    for(int i=1;i<=n;i++)wrn(ans[i]);
}