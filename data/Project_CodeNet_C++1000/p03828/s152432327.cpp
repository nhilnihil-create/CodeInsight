#include<bits/stdc++.h>
#define MAX 1000
#define MOD 1000000007
using namespace std;
long long ep[MAX+1];
void fact(int x)
{
	for(int i=2;i*1LL*i<=x;++i)
		while(x%i==0)
			++ep[i], ep[i] %= MOD,x /= i;
	if(x^1)
		++ep[x],ep[x] %= MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=2;i<=n;++i)
		fact(i);
	long long ans = 1;
	for(int i=2;i<=n;++i)
		ans *= (++ep[i])%MOD, ans %= MOD;
	cout<<ans<<endl;
	return 0;
}