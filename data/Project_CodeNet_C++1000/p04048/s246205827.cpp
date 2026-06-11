#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n, x, ans;

int main()
{
	cin >> n >> x;
	ans = n;
	
	LL a = x, b = n - x, t; //a存长边,b存短边 
	while(true)
	{
		if(a < b) swap(a,b);
		//cout << a << " " << b << endl;
		
		if(b == 0) break;
		
		ans += 2 * b * (a / b);
		if(a % b == 0) ans -= b;
		
		t = a % b; a = b; b = t;
	}
	
	cout << ans << endl;
	
	return 0;
}
