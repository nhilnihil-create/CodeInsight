#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005
int A[N], n;
bool cmp(int a, int b){return a > b;}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	sort(A + 1, A + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (i <= A[i] && A[i + 1] < i + 1)
		{
			int j = 0;
			while (A[i + j + 1] == i)
				j++;
			if ((A[i] - i) % 2 == 0 && j % 2 == 0)
				puts("Second");
			else
				puts("First");
			return 0;
		}
	}
}
