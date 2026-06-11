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
	int g = 2;
	for (int i = 1; i <= n; i++)
	{
		lst[g]++;
		g *= 2;
		if (g >= 100) break;
	}
	for (int i = n; i >= 2; i--)
	{
		if (lst[i])
		{
			g = i;
			break;
		}
	}
	if (n == 1)cout << 1;
	else
	cout << g;
}