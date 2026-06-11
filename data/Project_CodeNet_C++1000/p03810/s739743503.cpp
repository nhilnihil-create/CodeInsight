#include<bits/stdc++.h>
using namespace std;
int n,ans,a[200005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1) return puts("Second"),0;
	for (;;){
		int k0=0,k1=0,x;
		for (int i=1;i<=n;i++)
			if (a[i]&1) k1++,x=i;
			else k0++;
		if (k0&1){
			ans^=1;
			break;
		}
		if (k1>1||a[x]==1)
			break;
		a[x]--;
		int k=a[1]; ans^=1;
		for (int i=2;i<=n&&k>2;i++)
			k=gcd(k,a[i]);
		for (int i=1;i<=n;i++)
			a[i]/=k;
	}
	puts(ans?"First":"Second");
} 