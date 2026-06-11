//I love Nanami Chiaki
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int re=0;char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {re=(re<<1)+(re<<3)+c-'0';c=getchar();}
	return re;
}
inline int readc(){
	char c=getchar();
	while (c!='+' && c!='-') c=getchar();
	if (c=='+') return 1;
	return -1;
}
int n;
ll ans=0;
int main(){
	int n=read();
	ans+=read();
	int op,a;
	ll hve=0,add=-1,pre=-1;
	for (int i=1;i<n;i++){
		op=readc();a=read();
		ans+=a;
		if (op==-1){
			if (pre==-1){
				pre=a;
				hve=0;
				continue;
			}
			if (add==-1) add=pre+hve;
			else add=min(add,pre+hve);
			pre+=a;
			hve=0;
		}
		else{
			hve+=a;
		}
	}
	if (pre==-1){
		printf("%lld\n",ans);
		return 0;
	}
	else if (add==-1) ans-=2*pre;
	else ans-=2*add;
	printf("%lld\n",ans);
	return 0;
}