#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
llint x[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	
	llint ans = 1, cnt = 0, jump = 1;
	while(cnt < n){
		while(jump < n-1 && x[jump+1] >= 2*(jump+1-cnt)-1) jump++;
		ans *= jump+1 - cnt, ans %= mod;
		cnt++;
	}
	cout << ans << endl;
	
	return 0;
}