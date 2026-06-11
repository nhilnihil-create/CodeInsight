#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	int x = 0;
	for (auto o : s)
	{
		x += (o == 'I'?1:-1);
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}