#include<bits/stdc++.h>
using namespace std;

int n,a[100009];
int gcd(int x,int y){ return y?gcd(y,x%y):x; }
bool solve(){
	if (n==1) return a[1]!=1;
	int i,x;
	if (n&1){
		for (i=1,x=0; i<=n; i++) x^=a[i];
		if (!(x&1)) return 1;
		for (i=1,x=0; i<=n; i++)if (a[i]&1) x++;
		if (x>1) return 0;
		for (i=1,x=0; i<=n; i++){
			if (a[i]&1)	a[i]--;
			if (!a[i]) return 0; x=gcd(x,a[i]);
		}
		for (i=1; i<=n; i++) a[i]/=x;
		return !solve();
		
	} else{
		for (i=1,x=0; i<=n; i++) x^=a[i];
		return x&1;
	}
}
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	puts(solve()?"First":"Second");
	return 0;
}
