#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[7];
  	for (int i = 0; i < 7; i++)
      	scanf("%d", a + i);
  	long long res = a[1];
  	if (a[0] && a[3] && a[4] && a[0] % 2 + a[3] % 2 + a[4] % 2 > 1) {
  		res += 3;
  		a[0]--, a[3]--, a[4]--;
  	}
  	res += (a[0] / 2) * 2;
  	res += (a[3] / 2) * 2;
  	res += (a[4] / 2) * 2;
  	printf("%lld\n", res);
  	return 0;
}
