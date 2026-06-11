#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 100010;
const int M = 1000000007;

int n,m;
ll ans;
ll fac[maxn];

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	ans = 0;
	n = read(), m = read();
	
	if(n<m) swap(n,m);
	
	fac[1] = 1;
	for(int i = 2; i <= 100000; i++){
		fac[i] = 1LL * fac[i-1] * i % M;
	}
	
	
	if(n - m > 1) ans = 0;
	else{
		ans = 1LL * fac[n] * fac[m] % M;
	}
	if(m == n) ans = 1ll* ans * 2 % M;
	
	printf("%lld\n",ans);
	
	return 0;
}