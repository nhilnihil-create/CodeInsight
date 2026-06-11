#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n,a[N];

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

bool solve(){
	int t=0;
	for (int i=1;i<=n;i++) t+=a[i]&1;
	if ((n-t)&1) return 1;
	if (t>1) return 0;
	for (int i=1;i<=n;i++){
		if (a[i]==1) return 0;
		a[i]&=0x7ffffffe;
	}
	t=a[1];
	for (int i=2;i<=n;i++) t=gcd(t,a[i]);
	for (int i=1;i<=n;i++) a[i]/=t;
	return !solve();
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	printf(solve()?"First\n":"Second\n");
	return 0;
}