#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	char a[N + 1];
	char b[N + 1];
	f(i, N + 1) {
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	scanf("%s", a);
	a[n] = a[0];
	b[0] = 'S';
	b[1] = 'S';
	f(i, n) {
		if (a[i + 1] == 'o') {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
		}
		else {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
		}
	}
	if ((b[0] == b[n]) && (b[1] == b[n + 1])) {
		b[n] = 0;
		b[n + 1] = 0;
		printf("%s", b);
		return 0;
	}
	b[0] = 'W';
	b[1] = 'S';
	f(i, n) {
		if (a[i + 1] == 'o') {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
		}
		else {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
		}
	}
	if ((b[0] == b[n]) && (b[1] == b[n + 1])) {
		b[n] = 0;
		b[n + 1] = 0;
		printf("%s", b);
		return 0;
	}
	b[0] = 'S';
	b[1] = 'W';
	f(i, n) {
		if (a[i + 1] == 'o') {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
		}
		else {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
		}
	}
	if ((b[0] == b[n]) && (b[1] == b[n + 1])) {
		b[n] = 0;
		b[n + 1] = 0;
		printf("%s", b);
		return 0;
	}
	b[0] = 'W';
	b[1] = 'W';
	f(i, n) {
		if (a[i + 1] == 'o') {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
		}
		else {
			if (b[i + 1] == 'S') {
				if (b[i] == 'S') {
					b[i + 2] = 'W';
				}
				else {
					b[i + 2] = 'S';
				}
			}
			else {
				if (b[i] == 'S') {
					b[i + 2] = 'S';
				}
				else {
					b[i + 2] = 'W';
				}
			}
		}
	}
	if ((b[0] == b[n]) && (b[1] == b[n + 1])) {
		b[n] = 0;
		b[n + 1] = 0;
		printf("%s", b);
		return 0;
	}


	printf("-1\n");


	return 0;
}