#include <iostream>
#define llint long long

using namespace std;

llint n, x;
llint ans;

llint calc(llint a, llint b)
{
	if(a < b){
		return calc(b, a);
	}
	if(b == 0) return a;
	ans += a/b*b*2;
	return calc(b, a%b);
}

int main(void)
{
	cin >> n >> x;
	
	ans += n;
	ans -= calc(x, n-x);
	cout << ans << endl;
	
	return 0;
}