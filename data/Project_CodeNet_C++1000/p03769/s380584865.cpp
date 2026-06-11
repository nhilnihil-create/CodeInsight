#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

LL n;
int ans1[2010],ans2[2010];
int s1,t1,s2,t2,p;

void solve(LL n){
	if (n==1)return;
	if (n&1){
		solve(n/2);
		ans1[++t1]=ans2[++t2]=++p;
	}
	else{
		solve(n-1);
		ans1[--s1]=ans2[++t2]=++p;
	}
}

int main(){
	scanf("%lld",&n);
	s1=t1=s2=t2=1000;
	p=ans1[1000]=ans2[1000]=1;
	solve(n);
	printf("%d\n",p*2);
	fo(i,s1,t1)printf("%d ",ans1[i]);
	fo(i,s2,t2)printf("%d ",ans2[i]);
	putchar('\n');
	return 0;
}