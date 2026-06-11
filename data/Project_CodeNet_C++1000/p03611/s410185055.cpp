#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
ll lst[Max];
int ls[Max];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int t;
		scanf("%d", &t);
		lst[t]++;
	}
	ll res = 0;
	for (int i = 1;i <= 1e5;i++)
	{
		res = max(res, lst[i - 1] + lst[i] + lst[i + 1]);
	}
	cout << res;
}