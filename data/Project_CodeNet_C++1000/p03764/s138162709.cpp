#include <iostream>
#define llint long long
#define mod 1000000007
using namespace std;

llint n, m;
llint x[100005], y[100005];

llint calc(llint p[], llint N)
{
	llint sum = 0, ret = 0, tmp;
	for(int i = 0; i < N; i++){
		tmp = (i*p[i]) % mod;
		tmp -= sum;
		tmp = (tmp + mod) % mod;
		sum += p[i];
		sum %= mod;
		ret += tmp;
		ret %= mod;
	}
	return ret;
}

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < m; i++) cin >> y[i];
	
	for(int i = 1; i < n; i++) x[i] -= x[0];
	for(int i = 1; i < m; i++) y[i] -= y[0];
	x[0] = y[0] = 0;
	
	cout << (calc(x, n) * calc(y, m)) % mod << endl;
	return 0;
}