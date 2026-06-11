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
int A[100010];
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n);
  int a=n,b=0;
  for(int i=1;i<=n;++i) {
    read(A[i]);
    a=min(a,A[i]);
    b=max(b,A[i]);
  }
  if(b-a>1) return puts("No"),0;
  if(a==b) {
    if(A[1]*2<=n||A[1]==n-1) puts("Yes");
    else puts("No");
    return 0;
  }
  int cnt=0;
  for(int i=1;i<=n;++i) if(A[i]==a) ++cnt;
  if(b-cnt>0&&(b-cnt)*2<=n-cnt) puts("Yes");
  else puts("No");
	return 0;
}
