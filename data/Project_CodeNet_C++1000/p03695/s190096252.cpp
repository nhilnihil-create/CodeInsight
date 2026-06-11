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
	int n;
	cin>>n;
	int any=0;
	set<int> s;
	REP(i,0,n-1) {
		int val;
		cin>>val;
		if(val>0&&val<400)s.insert(1);
		else if(val>399&&val<800)s.insert(2);
		else if(val>799&&val<1200)s.insert(3);
		else if(val>1199&&val<1600)s.insert(4);
		else if(val>1599&&val<2000)s.insert(5);
		else if(val>1999&&val<2400)s.insert(6);
		else if(val>2399&&val<2800)s.insert(7);
		else if(val>2799&&val<3200)s.insert(8);
		else any++;
	}
	cout<<max(1,(int)s.size())<<" "<<any+(int)s.size();
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
