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
	int va,vb,vc;
	cin>>va>>vb>>vc;
	int a,b,c,cnt=0;
	a=va,b=vb,c=vc;
	while(1) {
		if(va&1||vb&1||vc&1) {
			cout<<cnt;
			return;
		}
		int ta=vb/2+vc/2,tb=va/2+vc/2,tc=va/2+vb/2;
		cnt++;
		va=ta,vb=tb,vc=tc;
		if(va==a&&vb==b&&vc==c) {
			cout<<-1;
			return;
		}
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
