#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fac[20];
char response[3];

int main()
{
	/*string s1 = "123";
	string s2 = "1230";
	if (s1 >= s2) printf("s1 is bigger\n");
		else printf("s2 is bigger\n");*/
	fac[0] = 1;
	for (int i = 1; i <= 10; i++) fac[i] = fac[i - 1] * 10;	
	LL L = 0, R = 10;
	while (L < R - 1) {
		LL mid = (L + R) >> 1;
		printf("? %lld\n", fac[mid]);
		fflush(stdout);
		scanf("%s", response);
		if (response[0] == 'Y') L = mid; 
			else R = mid;
	}
	//printf("L : %lld\n", L);
	if (L == 9) {
		int ans = 0;
		for (int i = 0; i <= 9; i++) {
			printf("? %lld\n", fac[i] + 1);
			fflush(stdout);
			scanf("%s", response);
			if (response[0] == 'Y') {
				ans = i;
				break;
			}
		}
		printf("! %lld\n", fac[ans]);
		fflush(stdout);
	}
	else {
		L = fac[L] - 1; R = (L + 1) * 10 - 1;
		while (L < R - 1) {
			LL mid = (L + R) >> 1;
			printf("? %lld0\n", mid);
			fflush(stdout);
			scanf("%s", response);
			if (response[0] == 'Y') R = mid;
			else L = mid;
		}
		printf("! %lld\n", R);
		fflush(stdout);
	}
	return 0;	
}