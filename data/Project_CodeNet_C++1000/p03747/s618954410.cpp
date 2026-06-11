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
int n,L,T;
int G[100010];
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n,L,T);
  LL rk=0;
  for(int i=0;i<n;++i) {
    int a,w; read(a,w);
    if(w==1) {
      G[i]=(a+T)%L;
      rk+=(a+T)/L;
    }
    else {
      G[i]=(a-T)%L;
      rk+=(a-T)/L;
      if(G[i]<0) G[i]+=L,--rk;
    }
  }
  rk=(rk%n+n)%n;
  sort(G,G+n);
  for(int i=rk;i<n;++i) printf("%d\n",G[i]);
  for(int i=0;i<rk;++i) printf("%d\n",G[i]);
  return 0;
}
