#include <cstdio>
#include <vector>
#include <algorithm>

int n,m,c[100005];
std::vector<std::pair<int,int> > s[100005];

inline void Modify(int x,int v){for(;x<=m;x+=x&-x)c[x]+=v;}
inline int Query(int x,int s=0){for(;x;x^=x&-x)s+=c[x];return s;}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,l,r;i<=n;++i)
    {
        scanf("%d%d",&l,&r);
        s[r-l+1].push_back(std::make_pair(l,r));
    }
    for(int d=1;d<=m;++d)
    {
        for(auto i:s[d])Modify(i.first,1),Modify(i.second+1,-1),--n;
        int Ans=n;
        for(int i=d;i<=m;i+=d)Ans+=Query(i);
        printf("%d\n",Ans);
    }
    return 0;
}