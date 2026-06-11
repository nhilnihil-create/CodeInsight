#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;
typedef pair<int, int> T;
map<T, int>s;
int H, W, N;

int dir[9][2] = { -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1,0,0 };

void Fill(int x, int y)
{
	for (int i = 0; i < 9; ++i)
	{
		int tx = x + dir[i][0], ty = y + dir[i][1];
		if (tx<2 || ty<2 || tx>H - 1 || ty>W - 1) continue;
		++s[T{ tx,ty }];
	}
}

int result[10];

long long sum;

int main(void)
{
	scanf("%d%d%d", &H, &W, &N);
	int a, b;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &a, &b);
		Fill(a, b);
	}
	sum = ((long long)H - 2) * ((long long)W - 2);
	for (auto i = s.begin(); i != s.end(); ++i)
	{
		++result[i->second];
		--sum;
	}
	printf("%lld\n", sum);
	for (int i = 1; i <= 9; ++i)
		printf("%d\n", result[i]);
}