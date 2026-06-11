#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

const int N=105;

int p1,p2,m;
ll n;
int a[N],b[N];

int main(){
	int i;
	scanf("%lld",&n); n++;
	p1=p2=0; m=100;
	while (n>1){
		if (n&1ll) a[++p1]=m--,n--;
		else b[++p2]=m--,n>>=1;
	}
	printf("%d\n",(p1+p2)*2);
	for (i=1;i<=p1;i++) printf("%d ",a[i]);
	for (i=p2;i>=1;i--) printf("%d ",b[i]);
	for (i=1;i<=(p1+p2);i++) printf("%d ",m+i);
	return 0;
}