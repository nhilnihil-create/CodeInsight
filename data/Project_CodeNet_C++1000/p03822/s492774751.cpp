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
const int N=1e5+10;
int n;
int F[N];
vector<int> G[N];
bool cmp(int a,int b) {
  return F[a]>F[b];
}
void Solve(int u) {
  for(auto v: G[u]) Solve(v);
  sort(G[u].begin(),G[u].end(),cmp);
  for(int i=0;i<(int)G[u].size();++i) F[u]=max(F[u],F[G[u][i]]+i+1);
}
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n);
  for(int i=2;i<=n;++i) {
    int u; read(u);
    G[u].push_back(i);
  }
  Solve(1);
  printf("%d\n",F[1]);
  return 0;
}
