#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

int calc(vector <int> &v) {
	int c = -1, g = 0, i;
	long long sum = 0;
	
	sort(v.begin(), v.end());
	
	for (i = 0; i < v.size(); i++) sum += v[i] - 1;
	
	if (v[0] == 1) return sum % 2;
	if (sum % 2 == 1) return 1;
	
	for (i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 1) {
			if (c != -1) return 0;
			
			c = i;
		}
	}
	
	v[c]--;
	
	for (i = 0; i < v.size(); i++) g = gcd(g, v[i]);
	
	for (i = 0; i < v.size(); i++) v[i] /= g;
	
	return 1 - calc(v);
}

int main() {
	int n, i;
	vector <int> v;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		int x;
		
		scanf("%d", &x);
		
		v.push_back(x);
	}
	
	if (calc(v) == 1) {
		puts("First");
	} else {
		puts("Second");
	}
	
	return 0;
}
