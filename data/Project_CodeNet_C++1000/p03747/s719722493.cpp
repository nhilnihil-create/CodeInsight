#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int n,l,t,ans[N],wa,wb;
struct node
{
    int x,w,id;
}a[N];
node b[N],sh[N];
deque <int> s;
signed main()
{
    scanf("%lld%lld%lld",&n,&l,&t);
    for (int i=1;i<=n;i++)
    {
        int x,w;
        scanf("%lld%lld",&x,&w);
        sh[i].x=x,sh[i].w=w;
        if (w==1) a[++wa].x=x,a[wa].w=w,a[wa].id=i;
        else b[++wb].x=x,b[wb].w=w,b[wb].id=i;
    }
    if (wa==0 || wb==0)
    {
        for (int i=1;i<=n;i++)
        {
            if (sh[i].w==2) printf("%lld\n",(sh[i].x-t+l)%l);
            else printf("%lld\n",(sh[i].x+t)%l);
        }
        return 0;
    }
    for (int i=1;i<=wb;i++) s.push_back(b[i].x);
    for (int i=1;i<=wa;i++)
    {
        while (s.front()<a[i].x)
        {
            int x=s.front();
            s.pop_front();
            s.push_back(x+l);
        }
        int now=2ll*t,cnt=0;
        cnt=(now/l)*wb,now%=l;
        cnt+=upper_bound(s.begin(),s.end(),a[i].x+now)-s.begin();
        cnt%=n;
        if (a[i].id+cnt>n) sh[a[i].id].id=a[i].id+cnt-n;
        else sh[a[i].id].id=a[i].id+cnt;
    }
    s.clear();
    for (int i=1;i<=wa;i++) s.push_back(a[i].x);
    for (int i=wb;i>=1;i--)
    {
        while (s.back()>b[i].x)
        {
            int x=s.back();
            s.pop_back();
            s.push_front(x-l);
        }
        int now=2ll*t,cnt=0;
        cnt=(now/l)*wa,now%=l;
        cnt+=wa-(lower_bound(s.begin(),s.end(),b[i].x-now)-s.begin());
        cnt%=n;
        if (b[i].id-cnt<1) sh[b[i].id].id=n+b[i].id-cnt;
        else sh[b[i].id].id=b[i].id-cnt;
    }
    t%=l;
    for (int i=1;i<=n;i++)
    {
        if (sh[i].w==2) ans[sh[i].id]=(sh[i].x-t+l)%l;
        else ans[sh[i].id]=(sh[i].x+t)%l;
    }
    for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}