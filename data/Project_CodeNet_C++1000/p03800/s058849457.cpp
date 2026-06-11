#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<int,int>
#define print(n) cout<<n<<endl
const int M=100010;
const int MOD=1000000007;
const int INF=1000000007;
using ll=long long;


int n;
string s,t;
void check(string *u){
	REP(i,1,n){
		if(s[i]=='o'){
			if(t[i]=='S'){
				if(t[i-1]=='S')t+="S";
				else t+="W";
			}else{
				if(t[i-1]=='S')t+="W";
				else t+="S";
			}
		}else{
			if(t[i]=='S'){
				if(t[i-1]=='S')t+="W";
				else t+="S";
			}else{
				if(t[i-1]=='S')t+="S";
				else t+="W";
			}
		}
	}
	if(s[0]=='o'){
		if(t[0]=='S'){
			if(t[n-1]=='S')t+="S";
			else t+="W";
		}else{
			if(t[n-1]=='S')t+="W";
			else t+="S";
		}
	}else{
		if(t[0]=='S'){
			if(t[n-1]=='S')t+="W";
			else t+="S";
		}else{
			if(t[n-1]=='S')t+="S";
			else t+="W";
		}
	}
}
int main(){
	cin>>n>>s;
	t="SS";
	check(&t);
	if(t[0]==t[n]&&t[1]==t[n+1]){
		rep(i,n)cout<<t[i];
		return 0;
	}
	t="SW";
	check(&t);
	if(t[0]==t[n]&&t[1]==t[n+1]){
		rep(i,n)cout<<t[i];
		return 0;
	}
	t="WS";
	check(&t);
	if(t[0]==t[n]&&t[1]==t[n+1]){
		rep(i,n)cout<<t[i];
		return 0;
	}
	t="WW";
	check(&t);
	if(t[0]==t[n]&&t[1]==t[n+1]){
		rep(i,n)cout<<t[i];
		return 0;
	}
	cout<<-1<<endl;
}