#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define FUP(i,x,y) for(int i=(x);i<=(y);i++)
#define FDW(i,x,y) for(int i=(x);i>=(y);i--)
#define MAXN 510
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define db double
using namespace std;
int read(){
    int w=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')flg=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){w=w*10-'0'+ch,ch=getchar();}
    return w*flg;
}
struct node{
	int pos,data;
}b[MAXN];
bool cmp(node p,node q)
{
	return p.pos<q.pos;
}
int n,x[MAXN];
int a[MAXN*MAXN],need[MAXN*MAXN],now[MAXN*MAXN];
int num[MAXN*2],used[MAXN*2],cnt=1;
int main(){
	n=read();
	FUP(i,1,n)
	{
		x[i]=b[i].pos=read();
		b[i].data=i;
		a[x[i]]=i;
		need[x[i]]=i-1;
	}
	sort(b+1,b+n+1,cmp);
	FUP(i,1,n) num[i]=b[i].pos,used[i]=b[i].data-1;
	FUP(i,n+1,2*n) num[i]=b[i-n].pos,used[i]=n-1-used[i-n];
	FUP(i,1,n*n)
	{
		if(a[i])
		{
			if(need[i]!=now[i])
			{
				puts("No");
				return 0;
			}
		}
		else
		{
			while(used[cnt]==0) cnt++;
			used[cnt]--;
			a[i]=a[num[cnt]];
			now[num[cnt]]++;
		}
	}
	puts("Yes");
	FUP(i,1,n*n) printf("%d ",a[i]);
    return 0;
}