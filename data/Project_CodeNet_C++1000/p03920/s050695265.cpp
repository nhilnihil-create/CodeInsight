#include <bits/stdc++.h>
 
using namespace std;
long long power[64];
std::vector<int> tmpRes, res;

int main() {
	
	//freopen("test.inp", "r", stdin);
	int n;
	scanf("%d", &n);
 
	int t = 1, sum = 0;

	while (sum < n) {
		sum +=t;
		t ++;
	}
	
	for (int i = 1; i <= t-1; i++){
		if (i != sum - n) {
			printf("%d\n", i);
		}
	}
}