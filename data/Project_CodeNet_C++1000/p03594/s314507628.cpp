#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define re register
#define N 310000
#define mod 998244353
using namespace std;

inline int read(){
    int x=0,w=0;char ch=getchar();
    while (!isdigit(ch))w|=ch=='-',ch=getchar();
    while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return w?-x:x;
}
const char s[]={'R','Y','G','B'};
signed main(){
	int h=read(),w=read(),d=read();
	for (int i=1;i<=h;++i,puts(""))
		for (int j=1;j<=w;++j){
			int x=i+j+w,y=i-j+w;
			putchar(s[((x/d)&1)*2+((y/d)&1)]);
		}
    return 0;
}
