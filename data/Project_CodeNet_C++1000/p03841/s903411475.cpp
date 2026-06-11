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
int A[250010],X[510],ID[510],cnt[510];
bool cmp(int a,int b) {
  return X[a]<X[b];
}
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
//  freopen("data.in","r",stdin);
//  freopen("data.out","w",stdout);
  read(n);
  for(int i=1;i<=n;++i) read(X[i]),A[X[i]]=i,ID[i]=i,cnt[i]=1;
  sort(ID+1,ID+n+1,cmp);
  for(int i=1;i<=n*n;++i) {
    if(A[i]) continue;
    for(int j=1;j<=n;++j) {
      int t=ID[j];
      if(cnt[t]!=t) {
        A[i]=t,++cnt[t];
        break;
      }
    }
  }
  for(int i=n*n;i;--i) {
    if(A[i]) continue;
    for(int j=n;j;--j) {
      int t=ID[j];
      if(cnt[t]!=n) {
        A[i]=t,++cnt[t];
        break;
      }
    }
  }
  for(int i=1;i<=n;++i) {
    int t=0;
    for(int j=1;j<=X[i];++j) {
      if(A[j]==i) ++t;
    }
    if(t!=i) return puts("No"),0;
  }
  puts("Yes");
  for(int i=1;i<=n*n;++i) printf("%d ",A[i]);
  return 0;
}
