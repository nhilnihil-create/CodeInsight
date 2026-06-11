#include <bits/stdc++.h>
using namespace std;

int n,A,B,a[100000];

bool check(int cnt) {
	int t=0;
	for(int i=0;i<n;i++) if(a[i] > 1ll*cnt*B) {
		t += (a[i]-cnt*B + (A-B)-1) / (A-B);
		if(t > cnt) return false;
	}
	return true;
}
int main() {
	scanf("%d%d%d",&n,&A,&B);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	int lo=0,up=1e9;
	while(up-lo>1) {
		int md=(lo+up)>>1;
		if(check(md)) up=md;
		else lo=md;
	}
	printf("%d\n",up);

	return 0;
}
