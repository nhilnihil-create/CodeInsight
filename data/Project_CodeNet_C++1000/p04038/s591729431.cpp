#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo = 1000000007;
const int Maxn = 2005;
void upd(int & x,int y)
{
	x = (x + y) % mo;
}
int getinv(int x)
{
	if(x == 1)
		return 1;
	return (ll)getinv(mo%x) * (mo - mo/x) % mo;
}
int fac[Maxn * Maxn];
int invf[Maxn * Maxn];
void Init(int n)
{
	fac[0] = 1;
	for(int i=1;i<=n;i++)
		fac[i] = (ll)fac[i-1] * i % mo;
	invf[n] = getinv(fac[n]);
	for(int i=n;i;i--)
		invf[i-1] = (ll)invf[i] * i % mo;
}
int C(int n,int m)
{
	if(m > n)
		return 0;
	return (ll)fac[n] * invf[m] % mo * invf[n-m] % mo;
}
int dp[Maxn][Maxn];
int main()
{
	int n,K;
	cin >> n >> K;
	if(K == 1) {
		cout << 1 << endl;
		return 0;
	}
	Init(n*K + 1);

	dp[0][0] = 1;
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++) {
			if(i != 0)
				upd(dp[i][j] , dp[i-1][j]);
			if(j != 0 && i != j) {
				int t1 = (j-1)*(K-1) + i;
				int t2 = K-2;
				upd(dp[i][j] , (ll)dp[i][j-1] * C(t1+t2 , t1) % mo);
			}
		}
	cout << (ll)dp[n][n] * fac[n] % mo << endl;
	return 0;
}
