/*program from Wolfycz*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
inline char gc(){
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int frd(){
	int x=0,f=1; char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=gc())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline void print(int x){
	if (x<0)	putchar('-'),x=-x;
	if (x>9)	print(x/10);
	putchar(x%10+'0');
}
const int N=5e2,inf=1e9;
int V[N+10][N+10];
int main(){
	int n=read(),m=read(),h=read(),w=read();
	int v=3999,mv=-(h*w-1)*v-1,sum=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			sum+=V[i][j]=(i%h==0&&j%w==0)?mv:v;
	if (sum<=0)	printf("No\n");
	else{
		printf("Yes\n");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)	printf("%d ",V[i][j]);
			putchar('\n');
		}
	}
	return 0;
}