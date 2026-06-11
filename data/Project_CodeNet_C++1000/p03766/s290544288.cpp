#include<bits/stdc++.h>
using namespace std;
const int _=1e6+5,yl=1e9+7;
int n,f[_],ans=1;
void inc(int &x,int y){x+=y;if(x>=yl)x-=yl;}
void dec(int *x,int y){x-=y;if(x<0)x+=yl;}	
int main(){
	cin>>n;int s=1ll*(n-1)*(n-1)%yl; f[1]=1;
	for(int i=1,x=1,y=0;i<=n;++i){
		f[i+1]=x;inc(x,y);inc(y,f[i]);
		if(i<n)inc(ans,1ll*f[i]*s%yl);
		inc(ans,1ll*f[i]*(n-1)%yl);
	}
	cout<<ans<<endl;
}
