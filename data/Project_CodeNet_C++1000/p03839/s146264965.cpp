#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

long long int l[500000];
long long int ma[500000];
int n, k;

int main() {
	
	cin >>n >>k;
	
	cin >>l[0];
	if (l[0] < 0) {
		ma[0] = 0;
	}
	else {
		ma[0] = l[0];
	}
	for (int i=1; i<n; i++) {
		int a;
		cin >>a;
		l[i] = l[i-1]+a;
		ma[i] = max(ma[i-1]+a, ma[i-1]);
	}
	
	int p = -1;
	long long int maxi = 0;
	for (int i=k-1; i<n; i++) {
		long long int val = l[i];
		if (p >= 0) {
			val-=l[p];
			val+=ma[p];
		}
		val += ma[n-1]-ma[i];
		if (val > maxi) {
			maxi = val;
		}
		p++;
	}
	p = -1;
	for (int i=k-1; i<n; i++) {
		long long int val = 0;
		if (p >= 0) {
			val+=ma[p];
		}
		val += ma[n-1]-ma[i];
		if (val > maxi) {
			maxi = val;
		}
		p++;
	}
	
	cout <<maxi;
	
	return 0;
}
