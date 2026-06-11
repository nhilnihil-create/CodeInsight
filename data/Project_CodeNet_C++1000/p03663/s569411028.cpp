#include<cstdio>
#include<algorithm>
using namespace std;
long long po[15];
int Query(long long a) {
	printf("? %lld\n", a);
	fflush(stdout);
	char p[3];
	scanf("%s", p);
	if (p[0] == 'Y')return 1;
	return 0;
}
int ck1[15], ck2[15];
void Answer(long long a) {
	printf("! %lld\n", a);
	fflush(stdout);
}
void Do() {
	int i;
	po[0] = 1;
	for (i = 1; i < 15; i++)po[i] = po[i - 1] * 10;
	int n1 = -1, n2 = -1;
	for (i = 0; i < 10; i++) {
		ck1[i] = Query(po[i]);
		if (!ck1[i] && n1 == -1)n1 = i;
	}
	if (n1 == -1) {
		for (i = 1; i <= 10; i++) {
			ck2[i] = Query(po[i] - 1);
			if (!ck2[i])n2 = i;
		}
		if (n2 == -1) {
			Answer(1);
			return;
		}
		Answer(po[n2]);
		return;
	}
	long long b = po[n1], e = po[n1+1] - 1, r = 0, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Query(mid))r = mid, e = mid - 1;
		else b = mid + 1;
	}
	Answer(r/10);
}
int main() {
	Do();
}