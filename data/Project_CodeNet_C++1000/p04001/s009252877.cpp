#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,ANS;
bool insrt[11];
bool b=0;
ll check(){
	ll bans=0,ans=0;
	for(ll i=0;i<s.size();i++){
		if(insrt[i]){
			bans+=ans;
			ans=0;
		}
		ans=ans*10+s[i]-'0';
	}
	bans+=ans;
	return bans;
}
void dfs(ll a){
	if(a>s.size()-1){
		ANS+=check();
		return;
	}
	insrt[a]=0;
	dfs(a+1);
	insrt[a]=1;
	dfs(a+1);
	
}
int main(){
	cin>>s;
	insrt[0]=1;
	dfs(1);
	cout<<ANS;
}