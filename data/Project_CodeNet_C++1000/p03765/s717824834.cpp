#include <bits/stdc++.h>
using namespace std;

int ss[100001];
int tt[100001];

int main(){
	string s,t;
	cin>>s>>t;
	int q;
	cin>>q;
	for(int i=1;i<=s.length();i++){
		if(s[i-1]=='A'){
			ss[i]=ss[i-1]+1;
		}else{
			ss[i]=ss[i-1]+2;
		}
	}
	for(int i=1;i<=t.length();i++){
		if(t[i-1]=='A'){
			tt[i]=tt[i-1]+1;
		}else{
			tt[i]=tt[i-1]+2;
		}
	}
	int a,b,c,d;
	while(q--){
		cin>>a>>b>>c>>d;
		if(abs(ss[b]-ss[a-1]-tt[d]+tt[c-1])%3==0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}