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
int n,K;
LL A[100010],L[100010],R[100010],S[100010];
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n,K);
  for(int i=1;i<=n;++i) read(A[i]),S[i]=S[i-1]+A[i];
  for(int i=1;i<=n;++i) {
    L[i]=L[i-1];
    if(A[i]>0) L[i]+=A[i];
  }
  for(int i=n;i;--i) {
    R[i]=R[i+1];
    if(A[i]>0) R[i]+=A[i];
  }
  LL res=0;
  for(int i=1;i<=n-K+1;++i) res=max(res,L[i-1]+R[i+K]+max(0ll,S[i+K-1]-S[i-1]));
  printf("%lld\n",res);
  return 0;
}
