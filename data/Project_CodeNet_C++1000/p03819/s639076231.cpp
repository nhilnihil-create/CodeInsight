#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

const int maxn = 300100;
const int maxm = 100100;

struct edge{int l,r;}a[maxn];
int n,m;
int c[maxn];

void modify(int l,int r,int x){
	//printf("%d %d\n",l,r);
	c[l]+=x,c[r+1]-=x;
}

int main(){
	n=read(),m=read();
	//c[1]+=n;
	for(int i=1;i<=n;i++)
		a[i].l=read(),a[i].r=read();
	for(int i=1;i<=n;i++){
		int l=a[i].l,r=a[i].r;
		int block=sqrt(r);
		//printf("->>>>>%d %d %d\n",l,r,block);
		int x=0,last=0x7f7f7f7f;
		for(int j=1;j<=block;j++){
			int sl=l/j,sr=r/j;
			if(sl&&l%j) sl++;
			sr = min(last,sr);
			if(sl&&sl<=sr) modify(sl,sr,1);
			if(j==block) x=sl-1;
			last = sl-1;
		}
		int sb=r/block;
		for(int j=1;j<=min(sb,x);j++)
			if((l%j==0)||l/j<r/j) modify(j,j,1);
	}
	for(int i=1;i<=m;i++) c[i]+=c[i-1];
	for(int i=1;i<=m;i++)
		printf("%d\n",c[i]);
}