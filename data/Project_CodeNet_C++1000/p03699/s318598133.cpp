#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max];

bool compare(int a,int b)
{
	if (a < b)return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d", &lst[i]);
		sum += lst[i];
	}
	sort(lst + 1, lst + 1 + n, compare);
	if (sum % 10 != 0)cout << sum;
	else
	{
		int f = 1;
		for (int i = 1;i <= n;i++)
		{
			if (lst[i] % 10 != 0)
			{
				sum -= lst[i];
				f = 0;
				break;
			}
		}
		if (f)cout << 0;
		else
		cout << sum;
	}
}