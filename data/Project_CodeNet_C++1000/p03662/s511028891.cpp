#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> v[MN+5];
int mark[MN+5],q[MN+5],n,top,num[5];
int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int a=read(),b=read();
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q[top=mark[1]=1]=1;q[top=mark[n]=2]=n;
    for(int i=1;i<=top;++i)
    {
        ++num[mark[q[i]]];
        for(int j=0;j<v[q[i]].size();++j)
            if(!mark[v[q[i]][j]]) mark[q[++top]=v[q[i]][j]]=mark[q[i]];
    }
    puts(num[1]>num[2]?"Fennec":"Snuke");
    return 0;
}
