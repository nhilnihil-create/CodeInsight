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

void solve(int test_case) {
	int ax,ay,bx,by;
	cin>>ax>>ay>>bx>>by;
	string sol="";
	REP(i,1,by-ay) {
		sol+="U";
	}
	REP(i,1,bx-ax) {
		sol+="R";
	}
	REP(i,1,by-ay)sol+="D";
	REP(i,1,bx-ax+1)sol+="L";
	REP(i,1,by-ay+1) {
		sol+="U";
	}
	REP(i,1,bx-ax+1) {
		sol+="R";
	}
	sol+="DR";
	REP(i,1,by-ay+1)sol+="D";
	REP(i,1,bx-ax+1)sol+="L";
	sol+="U";
	cerr<<sol.length();
	cout<<sol;
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
