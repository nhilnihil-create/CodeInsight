#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 7;
int lst[Max];

int main()
{
	int n;
	cin >> n;
	int f = 0;
	for (int i = 1; i <= n; i++)scanf("%d", &lst[i]);
	int k = lst[1];
	for (int i = 1; i <= Max; i++)
	{
		if (k == 2)
		{
			f = i; break;
		}
		k = lst[k];
	}
	if (f) cout << f;
	else cout << -1;
}