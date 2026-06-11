#include <bits/stdc++.h>
#define int long long
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}
const int N=1e5+5;
int n,a[N],ans;
signed main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++) if(i>=a[i+1]){
		for(int j=i+1;a[j]==i;j++)
			ans^=1;
		if(ans||(a[i]-i)&1) puts("First");
		else puts("Second");
		return 0;
	}
}