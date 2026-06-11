#include<bits/stdc++.h>
using namespace std;
int h,t,q[205],sum;
long long s;
void solve(long long s){
	if (!s) return;
	if (s%2==0){
		solve(s-1);
		q[--h]=++sum;
	}
	else{
		solve(s/2);
		q[++t]=++sum;
	}
}
int main(){
	scanf("%lld",&s);
	h=50,t=49,sum=0;
	solve(s);
	printf("%d\n",sum*2);
	for (int i=h;i<=t;i++) printf("%d ",q[i]);
	for (int i=1;i<=sum;i++) printf("%d ",i);
}