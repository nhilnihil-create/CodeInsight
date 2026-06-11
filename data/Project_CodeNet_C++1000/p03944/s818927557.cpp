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
	int w,h,n;
	cin>>w>>h>>n;
	int x1=0,x2=w,y1=0,y2=h;
	while(n--) {
		int x,y,a;
		cin>>x>>y>>a;
		switch(a) {
			case 1: x1=max(x,x1);break;
			case 2: x2=min(x,x2);break;
			case 3: y1=max(y,y1);break;
			case 4: y2=min(y,y2);break;
		}
	}
	if(x2<=x1||y2<=y1)cout<<0;
	else
	cout<<(x2-x1)*(y2-y1);
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
