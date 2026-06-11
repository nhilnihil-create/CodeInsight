#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
	while(c<'0'||c>'9'){ if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
ll n,x,ans;
int main(){
	n=read(),x=read();ans=n;
	ll a=n-x,b=x;
	while(1){
		if(a<b) swap(a,b);
	//	cout<<a<<' '<<b<<endl;
		ans+=a/b*2*b;
		if(a%b==0){
			ans-=b;
			break;
		}
		a=a%b;
		
	}
	cout<<ans<<endl;
	return 0;
}
