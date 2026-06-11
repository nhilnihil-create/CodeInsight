#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100005];
int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
void write(int x)
{
    if (x==0) puts("First");
    else puts("Second");
    return;
}
void dfs(int s,int f,int now)
{
	//printf("%d %d %d %d\n",s,f,now,a[f]);
    if ((n-s)&1) 
    {
        write(now);
        return;
    }
    if (s>1) 
    {
        write(1-now);
        return;
    }
    a[f]--;
    if (a[f]==0) 
    {
    	write(1-now);
    	return;
	}
    int g=a[1];
    for (int i=2; i<=n; i++) g=gcd(g,a[i]);
    s=0;
    for (int i=1; i<=n; i++)
    {
        a[i]/=g;
        if (a[i]&1) s++,f=i;
    }
    dfs(s,f,1-now);
}
int main()
{
    scanf("%d",&n);
    int s=0,f=0;
    for (int i=1; i<=n; i++) 
    {
        scanf("%d",&a[i]);
        if (a[i]&1) s++,f=i;
    }
    dfs(s,f,0);
    return 0;
}