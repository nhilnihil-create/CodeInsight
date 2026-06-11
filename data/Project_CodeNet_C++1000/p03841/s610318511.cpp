/*program from Wolfycz*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x7f7f7f7f
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
const int N=5e2;
int cnt[N+10],A[N*N+10],C[N+10],B[N+10];
int pos[N+10][N+10];
bool cmp(int x,int y){return B[x]<B[y];}
bool check(int n){
	for (int i=1;i<=n*n;i++)	pos[A[i]][++pos[A[i]][0]]=i;
	for (int i=1;i<=n;i++)	if (pos[i][i]!=B[i])	return 0;
	return 1;
}
int main(){
	int n=read();
	for (int i=1;i<=n;i++)	C[i]=A[B[i]=read()]=i;
	sort(C+1,C+1+n,cmp);
	for (int i=1;i<=n;i++)	cnt[i]=i-1;
	for (int i=1;i<=n*n;i++){
		if (A[i])	continue;
		for (int j=1;j<=n;j++){
			if (cnt[C[j]]){
				cnt[A[i]=C[j]]--;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++)	cnt[i]=n-i;
	for (int i=n*n;i>=1;i--){
		if (A[i])	continue;
		for (int j=n;j>=1;j--){
			if (cnt[C[j]]){
				cnt[A[i]=C[j]]--;
				break;
			}
		}
	}
	if (!check(n)){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int i=1;i<=n*n;i++)	printf("%d",A[i]),putchar(i==n*n?'\n':' ');
	return 0;
}