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
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		res += (b - a+1);
	}
	cout << res;
}