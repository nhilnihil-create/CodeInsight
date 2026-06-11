#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
int lst[Max], ls[Max];
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d", &lst[i]);
	}
	int g = 1, d = 5, t = 1;
	int f = n % 2;
	if (f) t = -1;
	else t = 1;
	ls[d] = lst[g];
	while (++g <= n)
	{
		t = -t;
		ls[d + t * (g / 2)] = lst[g];
	}
	for (int i = d - n / 2;i <= d + (n - 1) / 2;i++)
		printf("%d ", ls[i]);
}