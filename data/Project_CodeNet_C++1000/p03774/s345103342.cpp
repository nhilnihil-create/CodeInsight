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
	int n,m;
	cin>>n>>m;
	vpii s(n),c(m);
	for(int i=0;i<n;i++) {
		cin>>s[i].F>>s[i].S;
	}
	for(int i=0;i<m;i++)cin>>c[i].F>>c[i].S;
	for(pair<int,int> p:s) {
		int dist = INT_MAX;
		int ind = -1;
		for(int j=0;j<m;j++) {
			pair<int,int> a=c[j];
			if(abs(p.F-a.F)+abs(p.S-a.S)<dist) {
				dist = abs(p.F-a.F)+abs(p.S-a.S);
				ind=j;
			}
		}
		cout<<ind+1<<"\n";
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
