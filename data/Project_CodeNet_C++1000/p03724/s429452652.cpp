#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
int n,m;
int a,b;
int c[100005];
int i;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		c[a]^=1;c[b]^=1;
	}
	rep(i,n) if(c[i]){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}