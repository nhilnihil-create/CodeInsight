#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N=2e5+5;
int f1[N],f2[N];
int find1(int x){
    if(f1[x]==x)
        return x;
    return f1[x]=find1(f1[x]);
}
int find2(int x){
    if(f2[x]==x)
        return x;
    return f2[x]=find2(f2[x]);
}
map<pair<int,int>,int>p;
int main()
{
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++)
        f1[i]=f2[i]=i;
    for(int i=1;i<=k;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        int a=find1(u),b=find1(v);
        f1[a]=b;
    }
    for(int i=1;i<=l;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        int a=find2(u),b=find2(v);
        f2[a]=b;
    }
    for(int i=1;i<=n;i++)
        p[make_pair(find1(i),find2(i))]++;
    for(int i=1;i<=n;i++)
        printf("%d ",p[make_pair(f1[i],f2[i])]);
}
