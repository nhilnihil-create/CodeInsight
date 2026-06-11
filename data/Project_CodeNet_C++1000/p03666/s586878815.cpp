#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ph push
#define ptc putchar
#define enter putchar('\n')
using namespace std;
typedef pair<int,int> pii;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef long long lnt;
inline int read(){
	   int x = 0;char c = getchar();
	   while (!isdigit(c)) c = getchar();
	   while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0' , c = getchar();
	   return x;
}
inline void write(int x){
	   if (!x){
          ptc('0');
          return;
	   }
	   int dg[20] , len = 0;
	   while (x) dg[len++] = x % 10 , x /= 10;
	   while (len--) ptc(dg[len]+'0');
}
inline void writeln(int x){
	   write(x);
	   ptc('\n');
}
int n , a , b , c , d;

int main(){
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	n--;
	
	b = abs(a - b);
	for (int i = 0;i <= n;i++){
		lnt L = 1ll * i * c - 1ll * (n - i) * d  , R = 1ll * i * d - 1ll * (n - i) * c;
		if (L <= b && b <= R){
			return puts("YES") , 0;
		}
	}
	return puts("NO") , 0;
}