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
	int n, k;
	cin >> n >> k;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		res += min(abs(k - t), t);
	}
	cout << 2 * res;
}