#include <map>
#include <cstdio>
typedef long long ll;

inline int Min(const int a,const int b){return a<b?a:b;}
inline int Max(const int a,const int b){return a>b?a:b;}

int n,a,ps;
int v[100005],p[100005],c[100005];
ll Ans[100005];
std::map<int,int> m1,m2;

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a);
        if(!m1[a])m1[a]=i;
        ++m2[a];
    }
    for(auto i:m1)v[++ps]=i.first,p[ps]=i.second,c[ps]=m2[i.first];
    //for(int i=1;i<=ps;++i)printf("%d %d %d\n",v[i],p[i],c[i]);
    for(int i=ps;i>=1;--i)
    {
        Ans[p[i]]+=ll(v[i]-v[i-1])*c[i];
        c[i-1]+=c[i],p[i-1]=Min(p[i-1],p[i]);
    }
    for(int i=1;i<=n;++i)printf("%lld\n",Ans[i]);
    return 0;
}