#include<bits/stdc++.h>
#define Fst first
#define Snd second
#define RG register
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef unsigned long long ULL;
template<typename T> inline void read(T& x) {
	char c = getchar();
	bool f = false;
	for (x = 0; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = true;
		}
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	if (f) {
		x = -x;
	}
}
template<typename T, typename... U> inline void read(T& x, U& ... y) {
	read(x), read(y...);
}
int n;
LL A[100010];
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n);
  LL a=1ll*(n+1)*n/2,b=0;
  for(int i=1;i<=n;++i) {
    read(A[i]);
    b+=A[i];
  }
  A[n+1]=A[1];
  if(b%a) return puts("NO"),0;
  LL cnt=b/a,g=0;
  for(int i=1;i<=n;++i) {
    if(A[i]<cnt||A[i]>cnt*n) return puts("NO"),0;
    A[i]=A[i]-A[i+1];
    if((A[i]+cnt)%n) return puts("NO"),0;
    g+=(A[i]+cnt)/n;
  }
  if(g!=cnt) puts("NO");
  else puts("YES");
  return 0;
}
