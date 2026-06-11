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
	string s;
	cin>>s;
	ll sum = 0;
	for(int i=0;i<(1<<((int)s.length()-1));i++) {
		vi pos;
		for(int j=0;j<(int)s.length()-1;j++) {
			if((i>>j)&1)
				pos.PUB(j+1);
		}
		pos.PUB((int)s.length());
		int last = 0;
		for(int j:pos) {
			sum+=stol(s.substr(last ,j-last));
			last=j;
		}
	}
	cout<<sum;
}//1 0 2 3 1
//1 1 3 6 7

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
