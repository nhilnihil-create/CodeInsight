#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000005
int n, A[N];
bool cmp(int a, int b){return a > b;}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, A + n, cmp);
	int k = 1;
	while (k + 1 <= n && A[k] >= k + 1)
		k++;
	int u = A[k - 1] - k;
	int r = 0;
	while (k + r < n && A[k + r] == k)
  		r++;
	if (u % 2 == 0 && r % 2 == 0)
		puts("Second");
	else
		puts("First");
}
