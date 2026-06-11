#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max];

int main()
{
	ll n;
	cin >> n;
	ll res1 = 0, sum = 0, res2 = 0;
	for (int i = 1;i <= n;i++)scanf("%d", &lst[i]);
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 1;i <= n;i++)
	{
		sum1 += lst[i];
		if (i % 2 == 1 && sum1 <= 0)
		{
			res1 += (1 - sum1);
			sum1 = 1;
		}
		else if (i % 2 == 0 && sum1 >= 0)
		{
			res1 += (sum1 + 1);
			sum1 = -1;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		sum2 += lst[i];
		if (i % 2 == 0 && sum2 <= 0)
		{
			res2 += (1 - sum2);
			sum2 = 1;
		}
		else if (i % 2 == 1 && sum2 >= 0)
		{
			res2 += (sum2 + 1);
			sum2 = -1;
		}
	}
	cout << min(res1, res2);
}