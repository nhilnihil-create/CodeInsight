#include <iostream>
#include <cmath>
#define llint long long 
#define inf (llint)1e16

using namespace std;

llint N;
llint a[200005];

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	
	llint y = 0;
	for(int i = 0; i < N; i++) y += a[i];
	
	llint ans = inf, x = 0;
	for(int i = 0; i < N-1; i++){
		x += a[i];
		y -= a[i];
		ans = min(ans, (llint)abs(x-y));
	}
	
	cout << ans << endl;
	return 0;
}