#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
const ll inf=1000000000000000000;
int a[maxn];
char s[maxn];
ll f0,f1,f2;
int i,j,k,l,t,n,m;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
char get(){
	char ch=getchar();
	while (ch!='+'&&ch!='-') ch=getchar();
	return ch;
}
int main(){
	n=read();a[0]=read();
	n--;
	fo(i,1,n){
		s[i]=get();
		a[i]=read();
	}
	f0=a[0];f1=f2=-inf;
	fo(i,1,n){
		if (s[i]=='-'){
			f0-=(ll)a[i];
			f1+=(ll)a[i];
			f2-=(ll)a[i];
			if (f1>f2) f2=f1;
			if (f0>f1) f1=f0;
		}
		else{
			f0+=(ll)a[i];
			f1-=(ll)a[i];
			f2+=(ll)a[i];
		}
		if (f2>f1) f1=f2;
		if (f1>f0) f0=f1;
	}
	printf("%lld\n",f0);
}