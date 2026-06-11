#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=100005;

int n;
int a[N];

int gcd(int x,int y){
	if (!y) return x;
	else return gcd(y,x%y);
}

bool solve(){
	int yi=0,er=0;
	for (int i=1;i<=n;i++){
		if (a[i]==1) yi++;
		if (!(a[i]&1)) er++;
	}
	if (er&1) return 1;
	if (er<n-1) return 0;
	if (yi>0) return 0;
	int g=0;
	for (int i=1;i<=n;i++){
		if (a[i]&1) a[i]--;
		g=gcd(a[i],g);
	}
	for (int i=1;i<=n;i++) a[i]/=g;
	return solve()^1;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (solve()) printf("First\n");
	else printf("Second\n");
	return 0;
}