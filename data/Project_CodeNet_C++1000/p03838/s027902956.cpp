/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

void solve(int test_case) {
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<0;
		return;
	}
	if(a==-b) {
		cout<<1;
		return;
	}
	if(a==0) {
		if(b<0)cout<<abs(b)+1;
		else cout<<b;
		return;
	}
	if(b==0) {
		if(a>0)cout<<a+1;
		else cout<<abs(a);
		return;
	}
	if(a<0&&b<0) {
		if(b<a){cout<<abs(b)-abs(a)+2;}
		else if(b>a){cout<<abs(a)-abs(b);}
	} else if(a>0&&b<0) {
		cout<<abs(a-abs(b))+1;
	} else if(a<0&&b>0) {
		cout<<abs(abs(a)-b)+1;
	} else {
		if(b>a)cout<<b-a;
		else cout<<a-b+2;
	}
			
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
