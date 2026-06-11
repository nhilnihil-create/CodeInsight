#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	int n, k, x, ans = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		if( x > k - x )
			ans += k - x;
		else
			ans += x;
	}
	cout << 2 * ans;
}