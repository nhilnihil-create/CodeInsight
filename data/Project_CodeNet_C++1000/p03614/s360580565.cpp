#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[100001];
int main() {
	int n,res=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n; ++i) {
		if (arr[i] == i) { swap(arr[i], arr[i + 1]); ++i; ++res; }
	}
	if (arr[n] == n) ++res;
	printf("%d", res);
}