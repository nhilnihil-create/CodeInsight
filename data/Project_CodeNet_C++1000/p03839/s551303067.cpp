#include <iostream>
#include <vector>
#define sum(l, r) (l > 0 ? sums[r - 1] - sums[l - 1] : (r > 0 ? sums[r - 1] : 0))
#define sum2(l, r) (l > 0 ? sums2[r - 1] - sums2[l - 1] : (r > 0 ? sums2[r - 1] : 0))
#define abs(x) (x < 0 ? -x : x)
using namespace std;
int main() {
	long long n, k;
	cin >> n >> k;
	
	vector <long long> ar(n);
	vector <long long> sums(n);	//Pozitivno
	vector <long long> sums2(n);	//sve
	
	long long x = 0;
	long long y = 0;
	
	for(long long i = 0; i < n; i++) {
		cin >> ar[i];
		y += ar[i];
		if(ar[i] > 0) x += ar[i];
		sums[i] = x;
		sums2[i] = y;
	}
	
	long long s;
	
	for(long long i = 0; i < n - k + 1; i++) {
		
		long long sm = sum2(i, i + k);
		
		long long z = sum(0, i) + sum(i + k, n);
		if(sm > 0) z += sm;
		
		if(z > s || i == 0) {
			s = z;
		}
	}
	
	cout << s;
	
	return 0;
}