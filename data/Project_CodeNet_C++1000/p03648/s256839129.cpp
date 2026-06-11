#include <bits/stdc++.h>
using namespace std;

long long k, n = 50, a[51];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> k;
	a[0] = 1;
	for(int i=1; i<n; ++i) a[i] = i;
	long long c = k / n;
	k %= n;
	for(int i=0; i<n; ++i) a[i] += c;
	for(int i=0; i<k; ++i){
		a[i] += n;
		for(int j=1; j<n; ++j)
			a[(i+j)%n] -= 1;
	}
	cout << n << "\n";
	for(int i=0; i<n; ++i) cout << a[i] << " \n"[i==n-1];
}