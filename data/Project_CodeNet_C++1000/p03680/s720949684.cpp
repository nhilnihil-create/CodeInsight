#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 100;

int n, a[N];

int main() {
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int ans = 0, pos = 1;
	while(pos) {
		ans++;
		int tmp = pos;
		pos = a[pos];
		a[tmp] = 0;
		
		if(pos == 2) {
			printf("%d\n", ans);
			return 0;
		}
	}
	
	puts("-1");
	return 0;	
} 