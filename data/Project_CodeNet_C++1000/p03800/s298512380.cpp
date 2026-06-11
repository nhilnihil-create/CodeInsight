#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll n;string s;
bool ans=false;
bool ch[100010];
void dep(bool one){
	for(ll i=1;i<n;i++){
		bool now=true;
		if(s[i]=='x'){
			now=false;
		}
		ll nex=i+1;
		if(nex==n){
			nex=0;
		}
		if(now==ch[i]){
			ch[nex]=ch[i-1];
		}
		else{
			ch[nex]=abs(ch[i-1]-1);
		}
	}
	if(ch[0]!=one){
		return;
	}
	bool nex;
	bool fi=true;
	if(s[0]=='x'){
		fi=false;
	}
	if(ch[0]==fi){
		nex=ch[n-1];
	}
	else{
		nex=abs(ch[n-1]-1);
	}
	if(ch[1]==nex){
		for(ll i=0;i<n;i++){
			if(ch[i]){
				cout << "S";
			}
			else{
				cout << "W";
			}
		}
		ans=true;
	}
}
int main() {
	cin>>n>>s;
	ch[0]=true;ch[1]=true;
	dep(ch[0]);
	if(ans){
		return 0;
	}
	ch[0]=true;ch[1]=false;
	dep(ch[0]);
	if(ans){
		return 0;
	}	
	ch[0]=false;ch[1]=false;
	dep(ch[0]);
	if(ans){
		return 0;
	}	
	ch[0]=false;ch[1]=true;
	dep(ch[0]);
	if(ans){
		return 0;
	}	
	cout << -1;
	// your code goes here
	return 0;
}