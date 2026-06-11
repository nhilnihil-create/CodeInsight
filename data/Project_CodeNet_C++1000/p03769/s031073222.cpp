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
LL n;
vector<int> G;
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n); ++n;
  int k=40;
  while(!(n>>k&1)) --k;
  int cnt=k;
  for(int i=0;i<k;++i) {
    if(n>>i&1) G.push_back(++cnt);
    G.push_back(i+1);
  }
  //G.push_back(k);
  printf("%d\n",G.size()*2);
  for(auto v: G) printf("%d ",v);
  for(int i=1;i<=k;++i) printf("%d ",i);
  for(int i=cnt;i>k;--i) printf("%d ",i);
  return 0;
}
