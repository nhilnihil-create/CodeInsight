/*program from Wolfycz*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x7f7f7f7f
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
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
const int N=1e2;
int v[N+10];
int main(){
	int n=read(),Max=-inf,Min=inf;
	for (int i=1;i<=n;i++){
		int x=read();
		Max=max(Max,x);
		Min=min(Min,x);
		v[x]++;
	}
	if (Min!=(Max+1)/2){
		printf("Impossible\n");
		return 0;
	}
	if (v[Min]!=(Max&1)+1){
		printf("Impossible\n");
		return 0;
	}
	for (int i=Min+1;i<=Max;i++){
		if (v[i]<2){
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	return 0;
}