#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	int n, ans = 0;
	cin >> n;
	int l, r;
	for(int i = 0; i < n; i++)
	{
		cin >> l >> r;
		ans += r - l + 1;
	}
	cout << ans;
}