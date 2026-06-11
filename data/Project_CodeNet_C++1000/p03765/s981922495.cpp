#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll sa[100010]={},ta[100010]={},q;

void init(){
	string s,t;
	cin>>s>>t>>q;
	rep(i,s.size()){
		if(s[i]=='A')sa[i+1]=1+sa[i];
		if(s[i]=='B')sa[i+1]=2+sa[i];
	}
	rep(i,t.size()){
		if(t[i]=='A')ta[i+1]=1+ta[i];
		if(t[i]=='B')ta[i+1]=2+ta[i];
	}
	rep(i,q){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<((sa[b]-sa[a-1])%3==(ta[d]-ta[c-1])%3?"YES":"NO")<<endl;
	}
}

int main(void){
	init();
	return 0;
}