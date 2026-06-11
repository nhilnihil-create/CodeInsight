#include <bits/stdc++.h>
using namespace std;

char str[10];
bool query(long long N)
{
	printf("? %lld\n", N);
	fflush(stdout);
	scanf("%s", str);
	return str[0] == 'Y';
}

int a[] = {0,9,99,999,9999,99999,999999,9999999,99999999,999999999};
bool ans[10];
int main()
{
	for (int i = 0; i <= 9; i++) ans[i] = query(a[i]+1);
	if (ans[9] == 1) {
		for (int i = 1; i <= 9; i++)
			if (query(a[i])) {
				printf("! %d\n", a[i-1]+1);
				fflush(stdout);
				return 0;
			}
		printf("! %d\n", a[9]+1);
		fflush(stdout);
		return 0; 
	} else {
		// cerr << "HAHA" << endl;
		int first_dey = 0;
		while (ans[first_dey]) first_dey++;
		int L = a[first_dey-1]+1, R = a[first_dey], Mid;
		// cerr << L << " " << R << endl;
		while (L <= R) {
			// cerr << L << " " << R << endl;
			Mid = (L+R)>>1;
			if (query(Mid*10ll+9)) R = Mid-1;
			else L = Mid+1;
		}
		printf("! %d\n", R+1);
		fflush(stdout);
	}
	return 0;
}
