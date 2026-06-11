#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(a,n) rep(i,0,n){ cout<<(i ? " ":"")<<a[i]; }cout<<endl;
const long mod = 1e9+7;
int main(){
	int N;cin>>N;
	string s,t;cin>>s>>t;
	long res;
	if(s[0]==t[0]) res=3;
	else res=6;
	rep(i,1,N){
		if(s[i-1]==s[i]) continue;
		if(s[i]==t[i]&&s[i-1]==t[i-1]) (res*=2)%=mod;
		if(s[i]!=t[i]&&s[i-1]!=t[i-1]) (res*=3)%=mod;
        if(s[i]!=t[i]&&s[i-1]==t[i-1]) (res*=2)%=mod;
	}cout<<res<<endl;
}