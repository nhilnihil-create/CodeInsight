#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
	ll n;
	string s;
	cin>>n>>s;
	ll x=s.size()-1;
	string ans[4]={"SS","SW","WS","WW"};
	for(int i=0;i<4;i++){
		for(int j=1;j<x;j++){
			if(s[j]=='o'){
				if(ans[i][j]=='S')ans[i]+=ans[i][j-1];
				else ans[i]+=(ans[i][j-1]=='S'?"W":"S");
			}else{
				if(ans[i][j]=='S')ans[i]+=(ans[i][j-1]=='S'?"W":"S");
				else ans[i]+=ans[i][j-1];
			}
		}
		char c,d;
		if(s[x]=='o'){
			if(ans[i][x]=='S')c=ans[i][x-1];
			else c=(ans[i][x-1]=='S'?'W':'S');
		}else{
			if(ans[i][x]=='S')c=(ans[i][x-1]=='S'?'W':'S');
			else c=ans[i][x-1];
		}
		if(s[0]=='o'){
			if(ans[i][0]=='S')d=ans[i][1];
			else d=(ans[i][1]=='S'?'W':'S');
		}else{
			if(ans[i][0]=='S')d=(ans[i][1]=='S'?'W':'S');
			else d=ans[i][1];
		}
		if(c==ans[i][0]&&d==ans[i][x]){
			cout<<ans[i]<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
