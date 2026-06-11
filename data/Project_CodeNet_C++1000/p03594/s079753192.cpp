#include <bits/stdc++.h>
#define MOD
#define MAXN
#define MAXM
#define LL long long
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define memmax(a) memset(a,0x3f,sizeof(a))
//#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=(x*10)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
const string S="RYGB";
//#undef int
int main(){
//#define int long long
	int h=read(),w=read(),d=read();
	for (register int i=1;i<=h;++i){
		for (register int j=1;j<=w;++j){
			int x=i+j+w,y=i-j+w;
			int p=((int)(x/d)+2)%2,q=((int)(y/d)+2)%2;
			putchar(S[(p<<1)+q]);
		}
		putchar('\n');
	}
}
