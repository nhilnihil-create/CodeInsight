#include<cstdio>
using namespace std;

const int MAXN = 200010;

int a[MAXN];

int main(){
	int N, x, cnt;
	scanf("%d %d", &N, &x);
	if (x == 1 || x == (N << 1) - 1){
		printf("No");
		return 0;
	}
	if (x == 2){
		a[N - 2] = 4, a[N - 1] = 1, a[N] = 2, a[N + 1] = 3;
		for (int i = 1; i < N - 2; ++i)
			a[i] = i + 4;
		for (int i = N + 2; i <= (N << 1) - 1; ++i)
			a[i] = i;
	}
	else if (x == (N << 1) - 2){
		a[N - 1] = (N << 1) - 3, a[N] = (N << 1) - 2, a[N + 1] = (N << 1) - 1, a[N + 2] = (N << 1) - 4;
		for (int i = 1; i < N - 1; ++i)
			a[i] = i;
		for (int i = N + 3; i <= (N << 1) - 1; ++i)
			a[i] = i - 4;
	}
	else {
		a[N - 2] = x + 2, a[N - 1] = x - 1, a[N] = x, a[N + 1] = x + 1, a[N + 2] = x - 2;
		cnt = 1;
		for (int i = 1; i < N - 2; ++i, ++cnt){
			if (cnt == x - 2)
				cnt = x + 3;
			a[i] = cnt;
		}
		for (int i = N + 3; i <= (N << 1) - 1; ++i, ++cnt){
			if (cnt == x - 2)
				cnt = x + 3;
			a[i] = cnt;
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= (N << 1) - 1; ++i)
		printf("%d\n", a[i]);
	return 0;
}
