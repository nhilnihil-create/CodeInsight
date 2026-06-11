#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint a, b, c, d, e, f, g;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c >> d >> e >> f >> g;
	
	llint ans = a/2*2+d/2*2+e/2*2;
	if(a%2 && d%2 && e%2) ans+=3;
	
	llint ans2 = 0;
	if(a && d && e){
		a--, d--, e--;
		ans2 += 3;
		ans2 += a/2*2+d/2*2+e/2*2;
	}
	ans = max(ans, ans2);
	ans += b;
	
	cout << ans << endl;
	
	return 0;
}