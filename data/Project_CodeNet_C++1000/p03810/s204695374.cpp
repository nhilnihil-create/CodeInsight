#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,a[N];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
bool check(){
	int tot=n&1;
	for (int i=1;i<=n;i++)
		tot^=a[i]&1;
	for (int i=1;i<=n;i++)
		if (a[i]==1)
			return tot;
	int o=0;
	for (int i=1;i<=n;i++)
		o+=a[i]&1;
	if (o>1)
		return tot;
	for (int i=1;i<=n;i++)
		if (a[i]&1)
			a[i]--;
	int g=a[1];
	for (int i=2;i<=n;i++)
		g=gcd(g,a[i]);
	for (int i=1;i<=n;i++)
		a[i]/=g;
	return !check();
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	puts(check()?"First":"Second");
	return 0;
}