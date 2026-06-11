#include<iostream>
using namespace std;
int main() {
	long long n; cin >> n;
	long long ans = 0;
	for (int i = 1; i <= 10000; i++) {
		ans += i;
		if (n <= ans) {
			for (int j = 1; j <= i; j++) 
				if (j != ans - n)printf("%d\n", j);
			return 0;
		}
	}
}