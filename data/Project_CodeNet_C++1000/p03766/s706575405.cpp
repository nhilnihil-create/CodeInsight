#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
#define ll long long
#define mod 1000000007
using namespace std;
int n, s[N];
ll f[N];
int main(){
	scanf("%d", &n);
	f[1]=n; f[2]=(ll)n*n%mod;
	s[0]=0; for(int i=1; i<=2; i++)s[i]=(s[i-1]+f[i])%mod;
	for(int i=3; i<=n; i++){
		f[i]=(f[i-1]+s[i-3]+(ll)(n-1)*(i-3)%mod+(ll)n*(n-i+2)%mod)%mod;
		s[i]=(s[i-1]+f[i])%mod;
	}
	printf("%d", f[n]);
	return 0;
}