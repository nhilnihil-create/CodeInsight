#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<'\n'

long long a[66];

const long long n=50;

int main(void) {
	long long k;
	cin>>k;
	for (int i=1; i<=n; i++) {
		a[i]=i+k/n-1;
	}
	k%=50;
	for (int i=1; i<=k; i++) {
		a[i]+=n+1;
	}
	puts("50");
	for (int i=1; i<=n; i++) {
		cout<<a[i]-k<<' ';
	}
	return 0;
}