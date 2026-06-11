#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long llint;

const int MAXL = 11;


int N, sol;
int pwr10[MAXL];
char A[MAXL], B[MAXL], C[MAXL];

void num_to_str(llint x, char C[]) {
	for (int i = 0; i < MAXL; ++i) C[i] = 0;
	for (int i = 0; x > 0; ++i, x /= 10) {
		C[i] = (x % 10) + '0';
	}
	reverse(C, C+strlen(C));
}

bool cmp_lesseq(llint x, llint y) {
	num_to_str(x, A);
	num_to_str(y, B);
#ifdef DEBUG
	printf("CONVERTED: %s %s %d\n", A, B, strcmp(A, B));
#endif
	return strcmp(A, B) <= 0;
}

bool ask(llint x) {
	bool ret;
	#ifdef DEBUG
		ret = (x <= N && cmp_lesseq(x, N)) || (x > N && !cmp_lesseq(x, N));
		printf("%lld ANS:%d\n", x, ret);
	#else
		printf("? %lld\n", x);
		fflush(stdout);
		scanf("%s", C);
		ret = strcmp("Y", C) == 0;
	#endif
	return ret;
}

int main() {
	#ifdef DEBUG
	N = rand() % ((int)1e9 - 1) + 1;
	N = 1;
	printf("NUM:%d\n", N);
	#endif
	pwr10[0] = 1;
	for (int i = 1; i < 10; ++i)
		pwr10[i] = 10 * pwr10[i-1];
	bool t = ask(1e9);
	if (t) {
		int lo = 0, hi = 9;
		while (lo < hi) {
			int mid = (lo+hi+1)/2;
			bool res = ask(2 * pwr10[mid-1]);
			if (res) {
				hi = mid-1;
			} else {
				lo = mid;
			}
		}
		sol = pwr10[lo];
	} else {
		int lo = 0, hi = 9;
		while (lo < hi) {
			int mid =(lo+hi+1)/2;
			bool res = ask(pwr10[mid]);
			if (res) {
				lo = mid;
			} else {
				hi = mid-1;
			}
		}
		hi = pwr10[lo+1]-1;
		lo = pwr10[lo];

		//printf("%d %d\n", lo, hi);

		while (lo < hi) {
			llint mid = (lo+hi)/2;
			bool res = ask(10*mid);
			if (res) {
				hi = mid;
			} else {
				lo = mid+1;
			}
		}
		sol = lo;
	}
	printf("! %d\n", sol);
	fflush(stdout);
	return 0;
}
