#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=10000005;

int n,m;
int a[N];

void solve(int n){
	int i,s;
	if (!n) return;
	for (i=1;i<=n;i++){
		s=n-i;
		if (1ll*s<=1ll*i*(i-1)/2){
			a[++m]=i;
			solve(n-i);
			return;
		}
	}
}

int main(){
	int i,j,s;
	scanf("%d",&n);
	solve(n);
	for (i=m;i;i--) printf("%d\n",a[i]);
	return 0;
}