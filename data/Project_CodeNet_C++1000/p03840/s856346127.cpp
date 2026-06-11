#include<cmath>
#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1000100;
inline ll read(){
	ll x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
int l,x,y;ll ans;
int main(){
	l=read();ans=read();read();
	x=read();y=read();read();read();
	//ans+=l/2*2;l%=2;
	//ans+=x/2*2;x%=2;
	//ans+=y/2*2;y%=2;
	if(x%2+y%2+l%2>1){
		if(x%2+y%2+l%2==3)ans+=3;
		if(x%2+y%2+l%2==2){
			if(y%2==0){
				if(y)ans+=3,y--;
			}
			if(x%2==0){
				if(x)ans+=3,x--;
			}
			if(l%2==0){
				if(l)ans+=3,l--;
			}
		}
	}
	ans+=l/2*2;l%=2;
	ans+=x/2*2;x%=2;
	ans+=y/2*2;y%=2;
	printf("%lld\n",ans);
	return 0;
}