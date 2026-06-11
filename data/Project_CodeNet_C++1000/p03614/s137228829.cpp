#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 987654321
#define ll long long

int N, cnt, res;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == i) cnt++;
		else
		{
			res += (cnt + 1) / 2;
			cnt = 0;
		}
	}
	res += (cnt + 1) / 2;

	printf("%d", res);
	return 0;
}