#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll a[50];
int main(){
	ll k;scanf("%lld",&k);
	rep(i,50){
		ll b=k/50+(k%50>i);
		a[i]=49+50*b-(k-b);
	}
	puts("50");
	rep(i,50){
		if(i)printf(" ");
		printf("%lld",a[i]);
	}
	puts("");
}
