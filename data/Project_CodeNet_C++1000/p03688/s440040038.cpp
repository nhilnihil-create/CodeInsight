#include <bits/stdc++.h>
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



int n;

void doit(){
	int ma=0,mi=1e9,cnt=0;
	read(n);
	for(int i=1,x;i<=n;i++){
		read(x);
		if(x>ma) ma=x,cnt=0;
		if(x==ma) cnt++;
		mi=min(mi,x);
	}
	if(ma-mi>1){
		puts("No");
		return ;
	}
	if(cnt==n){
		if(ma==n-1) puts("Yes");
		else{
			if(n/ma>=2) puts("Yes");
			else puts("No");
		}
		return ;
	}
	int alone=n-cnt;
	if(ma-alone>=1&&cnt/(ma-alone)>=2) puts("Yes");
	else puts("No");
}

signed main(){
	doit();
}