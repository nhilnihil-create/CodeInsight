#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
#define MAXN 100001

int A[MAXN];
int n;

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i] == i) {
			if (i == 1) 
				swap(A[i], A[i+1]);
			else if (i == n) 
				swap(A[i], A[i-1]);
			else if (A[i+1] != i)
				swap(A[i], A[i+1]);
			else
				swap(A[i], A[i-1]);
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}