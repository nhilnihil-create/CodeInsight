#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max], ls[Max];

int main()
{
	int n, m;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &lst[i]);
		sum += lst[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum + b - lst[a] << endl;
	}
}