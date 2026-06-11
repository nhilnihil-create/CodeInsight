#include <bits/stdc++.h>
using namespace std;

char buf[512][512];
char dat[5] = "RYGB";
set<pair<int, int> > vis;
int r, c, D;

int foo(int x)
{
	if (x <= 0) return -x;
	return x-1;
}

void dfs(int cx, int cy, int typ)
{
	auto it = vis.lower_bound(make_pair(cx, cy));
	if (it == vis.end() || *it != make_pair(cx, cy))
		vis.insert(it, make_pair(cx, cy));
	else
		return;
	bool did = false;
	int d = (D+1)/2;
	if (D&1)
	{
		for (int i = -d+1;i <= d-1;i++) for (int j = abs(i)-d+1;j <= d-abs(i)-1;j++)
		{
			if (cx+i >= 0 && cx+i < r && cy+j >= 0 && cy+j < c)
			{
				buf[cx+i][cy+j] = dat[typ];
				did = true;
			}
		}
		if (did)
		{
			dfs(cx+d, cy+d-1, typ^1);
			dfs(cx-d, cy-d+1, typ^1);
			dfs(cx+d-1, cy-d, typ^2);
			dfs(cx-d+1, cy+d, typ^2);
		}
	} else
	{
		for (int i = -d+1;i <= d-1;i++) for (int j = abs(i)-d+1;j <= d-abs(i);j++)
		{
			if (cx+i >= 0 && cx+i < r && cy+j >= 0 && cy+j < c)
			{
				buf[cx+i][cy+j] = dat[typ];
				did = true;
			}
		}
		if (did)
		{
			dfs(cx, cy+d+d, typ^1);
			dfs(cx, cy-d-d, typ^1);
			dfs(cx+d, cy+d, typ^2);
			dfs(cx-d, cy-d, typ^2);
		}
	}
}

int main()
{
	scanf("%d%d%d", &r, &c, &D);
	dfs(0, 0, 0);
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
#ifdef DEBUG
			if (buf[i][j] == 'R') printf("\x1b[31m");
			else if (buf[i][j] == 'G') printf("\x1b[32m");
			else if (buf[i][j] == 'Y') printf("\x1b[33m");
			else if (buf[i][j] == 'B') printf("\x1b[34m");
			if (buf[i][j] == 0) buf[i][j] = ' ';
#endif
			printf("%c", buf[i][j]);
#ifdef DEBUG
			printf("\x1b[0m");
#endif
		}
		printf("\n");
	}
	return 0;
}
