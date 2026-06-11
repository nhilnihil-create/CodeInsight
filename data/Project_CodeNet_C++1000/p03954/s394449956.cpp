#include <iostream>
#include <math.h>
using namespace std;

long long n,a[20000005],maxx;

bool sdown(int i,int j,int k) {
	return a[j]<=k && a[i]<=k;
}

bool sup(int i,int j,int k) {
	return a[j]>k && a[i]>k;
}

bool check(int k) {
	for(int i=0;i<n;i++) {
		if(sup(n+i,n+i+1,k) || sup(n-i,n-i-1,k)) return 0;
		if(sdown(n+i,n+i+1,k) || sdown(n-i,n-i-1,k)) return 1;
	}
	return sdown(1,1,k);
}

int main() {
	scanf("%lld",&n);
	for(int i=1;i<=2*n-1;i++) {
		scanf("%lld",&a[i]);
		//maxx=max(maxx,a[i]);
	}
	long long l=1,r=2*n-1;
	while(l<r) {
		long long mid=(l+r)/2;
		if(check(mid)) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	printf("%lld\n",r);
	
	return 0;
} 