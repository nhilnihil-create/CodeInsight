#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=10*x+(ch-'0'),ch=getchar();return x;
}
const int N=1e5+50;
int a[N],n,s0,s1;
int gcd(int x,int y) {return !y?x:gcd(y,x%y);}
bool dfs(int x) {
	int sum=0,flag=0;
	fo(i,1,n) if(a[i]%2) {a[i]--;break;}
	int g=a[1];
	fo(i,2,n) g=gcd(g,a[i]);
	fo(i,1,n)  {
		a[i]/=g;
		if(a[i]%2==0) sum++;
		if(a[i]==1) flag=1;
	}
	if(sum%2) return x^1;
	if(flag||n-sum!=1) return x;
	return dfs(x^1);
}
int main() {
	bool flag=0;
	n=read();
	fo(i,1,n) {
		a[i]=read(),(a[i]%2)?s1++:s0++;
		if(a[i]==1) flag=1;
	}
	if(s0%2) printf("First\n");
	else {
		if(flag||s1!=1) printf("Second\n");
		else if(dfs(1)) printf("First\n");
		else printf("Second\n");
	}
	return 0;
} 