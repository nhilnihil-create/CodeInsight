#include<bits/stdc++.h>

using namespace std;

#define N 120000

int n,a[N];

bool solve(){
	int odd=0,even=0;
	for (int i=1;i<=n;++i)
		if (a[i]&1) ++odd; else ++even;
	if (odd>1) return even&1;
	if (even&1) return 1;
	int d=0;
	for (int i=1;i<=n;++i){
		if (a[i]&1){
			if (a[i]==1) return 0;
			--a[i];
		}
		d=__gcd(d,a[i]);
	}
	for (int i=1;i<=n;++i) a[i]/=d;
	return !solve();
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	puts(solve()?"First":"Second");
	
	return 0;
}
			