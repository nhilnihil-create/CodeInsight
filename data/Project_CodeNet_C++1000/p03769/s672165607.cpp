#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int ans[500];
bool in[500];

int main() {
  ll n=0;
  scanf("%lld",&n);
  int cnt=0;
  while (n)
  	if (n&1) {
  		cnt++;
  		in[cnt]=0;
  		n>>=1;
	  }
	else {
	    cnt++;
	    in[cnt]=1;
	    n--;
	}
  int l=251,r=250;
  for(int i=cnt;i>0;i--)
    if (in[i]) ans[--l]=cnt-i+1; else ans[++r]=cnt-i+1;
  printf("%d\n",2*cnt);
  for(int i=l;i<=r;i++) printf("%d ",ans[i]);
  for(int i=1;i<=cnt;i++) printf("%d ",i);
  printf("\n");
  return 0;
}