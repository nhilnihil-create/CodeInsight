#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define MN 500
#define pa pair<int,int>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,a[MN*MN+5];
priority_queue<pa,vector<pa>,greater<pa> >q;
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        int p=read();a[p]=i;
        if(p<i) return 0*puts("No");
        for(int j=1;j<i;++j) q.push(make_pair(p-j,i));
    }
    for(int i=1;i<=n*n;++i)
    {
        if(q.size()&&q.top().first<i) return 0*puts("No");
        if(a[i])
        {
            for(int j=a[i]+1;j<=n;++j) q.push(make_pair(n*n,a[i]));
            continue;
        }
        if(!q.size()) return 0*puts("No");
        a[i]=q.top().second,q.pop();
    }
    puts("Yes");
    for(int i=1;i<=n*n;++i) printf("%d ",a[i]);
    return 0;
}
