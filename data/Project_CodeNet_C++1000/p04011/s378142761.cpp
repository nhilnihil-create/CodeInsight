#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k,x,y;
	cin >> n >> k >> x >> y;
	
	if(n < k)
		cout << x * n;
	else
		cout << (x*k) + (n-k) * y;

	return 0;
}
