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
int H,W,h,w;
int A[550][550];
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(H,W,h,w);
  int cnt=0;
  for(int i=h;i<=H;i+=h) {
    for(int j=w;j<=W;j+=w) {
      ++cnt;
      A[i][j]=1;
    }
  }
  int a=W*H-cnt,b=cnt,c=h*w;
  int g=a-b*(c-1),t=b;
  if(g>0) {
    int v=1;
    while(g*v<=t) v<<=1;
    puts("Yes");
    for(int i=1;i<=H;++i) {
      for(int j=1;j<=W;++j) {
        printf("%d ",A[i][j]?-c*v+v-1:v);
      }
      puts("");
    }
  }
  else puts("No");
	return 0;
}
