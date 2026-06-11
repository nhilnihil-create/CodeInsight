#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<memory.h>
using namespace std;
typedef long long ll;
const int Max = 4e5 + 5;
const int Mod = 1e9 + 7;
int lst[Max];

int main()
{
	int n;
	cin >> n;
	for (int i = 2;i <= n;i++)
	{
		int a = i;
		for (int j = 2;j <= a;j++)
		{
			while (a % j == 0)
			{
				lst[j]++;
				a /= j;
			}
		}
		if (a != 1) lst[a]++;
	}
	ll res = 1;
	for (int i = 2;i <= n;i++)
	{
		res = (res * (1 + lst[i])) % Mod;
	}
	cout << res;
}