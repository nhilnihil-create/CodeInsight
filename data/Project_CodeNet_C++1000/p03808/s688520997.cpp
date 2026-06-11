#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int a[N];
int d[N];

int main() {
	int n;
	cin >> n;
	long long v = (n*1ll*(n+1))/2;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if(sum % v == 0) {
		sum/=v;
		for (int i = 0; i < n; ++i) {
			d[i] = a[i] - a[(i+1)%n];
		}

		for (int i = 0; i < n; ++i) {
			d[i] += sum;
		}
		int ok = 1;
		for (int i =0 ; i < n; ++i) {
			if(!(d[i]%n == 0 && d[i] >= 0)) {
				ok = 0;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	} else {

		puts("NO");

	}

}
