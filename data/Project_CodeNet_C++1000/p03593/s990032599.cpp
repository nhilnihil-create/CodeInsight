#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;

int n, m, Tst, t[30];
char s[maxn][maxn];

void work1()
{
	int res = 0;
	for(int i = 1; i <= 26; ++i)
		res += (t[i] & 1);
	if(res != 1)
	{
		printf("No\n");
		return ;
	}
	res = 0;
	for(int i = 1; i <= 26; ++i)
		res += ((t[i] % 4) == 2 || (t[i] % 4) == 3);
	if(res > ((n + m - 2) >> 1))
	{
		printf("No\n");
		return ;
	}	
	printf("%s\n", ((((n + m - 2) >> 1) - res) & 1) == 0? "Yes": "No");
}

void work2()
{
	int res = 0;
	for(int i = 1; i <= 26; ++i)
		res += (t[i] & 1);
	if(res != 0)
	{
		printf("No\n");
		return ;
	}
	for(int i = 1; i <= 26; ++i)
		res += ((t[i] % 4) == 2);
	if(res > (m >> 1))
	{
		printf("No\n");
		return ;
	}	
	printf("Yes\n", (((m >> 1) - res) & 1) == 0? "Yes": "No");
}

void work3()
{
	int res = 0;
	for(int i = 1; i <= 26; ++i)
		res += (t[i] & 1);
	if(res != 0)
	{
		printf("No\n");
		return ;
	}
	for(int i = 1; i <= 26; ++i)
		res += ((t[i] % 4) == 2);
	if(res > (n >> 1))
	{
		printf("No\n");
		return ;
	}	
	printf("Yes\n", (((n >> 1) - res) & 1) == 0? "Yes": "No");
}

void work4()
{
	for(int i = 1; i <= 26; ++i)
		if((t[i] % 4) != 0)
		{
			printf("No\n");
			return ;
		}
	printf("Yes\n");
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; ++j)
			++ t[s[i][j]-'a'+1];
	}
	if((n & 1) == 1 && (m & 1) == 1)
		work1();
	else if((n & 1) == 1 && (m & 1) == 0)
		work2();
	else if((n & 1) == 0 && (m & 1) == 1)
		work3();
	else
		work4();
	return 0;
}
