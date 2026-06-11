#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
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

int digits(ll val) {
	int digs = 0;
	while(val>0) {
		digs++;
		val/=10;
	}
	return digs;
}

void solve(int test_case) {
	ll n;
	cin>>n;
	for(ll i=sqrt(n)+1;i>=1;i--) {
		if(n%i==0) {
			cout<<max(digits(i),digits(n/i));
			break;
		}
	}
}

int main() {
	
	////// FILE BASED IO////
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
}	
