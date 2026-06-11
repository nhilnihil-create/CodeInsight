#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 100050
int n,a[N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void print(int x) {
	puts((x&1)?"First":"Second");
	exit(0);
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	int cas=0;
	for(;;cas++) {
		int i,flg=0,s=0,odd=0;
		for(i=1;i<=n;i++) {
			if(a[i]==1) flg=1;
			s+=(a[i]-1);
			if(a[i]&1) odd++;
		}
		if(flg==1) print(cas+s);
		if(s&1) print(cas+1);
		if(odd>1) print(cas);
		for(i=1;i<=n;i++) if(a[i]&1) a[i]--;
		int t=0;
		for(i=1;i<=n;i++) t=gcd(a[i],t);
		for(i=1;i<=n;i++) a[i]/=t;
	}
}
