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

void solve(int test_case) {//209
	ll q,h,s,d,n;
	cin>>q>>h>>s>>d>>n;
	q*=4;h*=2;
	s=min(s,min(q,h));
	ll ans =0;
	if(n&1) {
		ans=min((n/2)*d+s,n*s);
	} else ans=min((n/2)*d,s*n);
	cout<<ans;
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
	//prefill();
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
