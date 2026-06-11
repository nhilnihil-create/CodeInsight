#include<bits/stdc++.h> 
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
inline int read(){
	int n=0,f=1;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if (c=='-') c=getchar(),f=-1;
	for(;c>='0'&&c<='9';c=getchar()) n=n*10+c-48;
	return n*f;
}
int i,j,n,a[maxn],t,x,now;ll sum;
int gcd(int x,int y){
	return (y)?gcd(y,x%y):x;
}
int main(){
	n=read();
	fo(i,1,n) a[i]=read(),sum+=a[i],t+=a[i]&1,t+=a[i]==1;
	if (!(n&1)){
		if (sum&1) puts("First");else puts("Second");
		return 0;
	}
	if (!(sum&1)) {
		puts("First");
		return 0;
	}
	if (t>1) {
		puts("Second");
		return 0;
	}
	for(;;){
		now^=1;
		fo(i,1,n) if (a[i]&1) {a[i]--;break;}
		x=a[1];
		fo(i,2,n) x=gcd(x,a[i]);
		t=sum=0;
		fo(i,1,n) a[i]/=x,sum+=a[i],t+=a[i]&1,t+=a[i]==1;
		if (!(sum&1)){
			if (!now) puts("First");else puts("Second");
			return 0;
		}
		if (t>1){
			if (now) puts("First");else puts("Second");
			return 0;
		}
	}	
}