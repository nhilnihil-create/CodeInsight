#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll f[1000005];

int main() {
  int n;
  scanf("%d",&n);
  f[1]=n;
  ll s=n-1;
  for(int i=2;i<=n;i++) {
  	if (i>=4) s=(s+f[i-3]-1+MOD)%MOD;
  	f[i]=(f[i-1]+(ll)(n-1)*(n-1)+s)%MOD;
  }
  printf("%lld\n",f[n]);
  return 0;
}