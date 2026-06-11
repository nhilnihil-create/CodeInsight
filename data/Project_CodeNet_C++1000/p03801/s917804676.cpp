#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,t,f,ans[N];
struct zz{
	int x,y;
}a[N];
int cmp(zz x,zz y){
	if (x.x==y.x) return x.y<y.y;
	else return x.x>y.x;
}
signed main(){
    scanf("%d",&n);
    t=2;f=1;
    for (int i=1;i<=n;i++)scanf("%d",&a[i].x),a[i].y=i;
    sort(a+1,a+n+1,cmp);
    while (t<=n){
        while (a[t].x==a[t-1].x) t++;
        ans[a[f].y]+=(a[f].x-a[t].x)*(t-1);
        if (a[t].y>a[f].y) a[f].x=a[t].x;
        else f=t;
        t++;
    }
    ans[a[f].y]+=a[f].x*n;
    for (int i=1;i<=n;i++)printf("%lld\n",ans[i]);
}