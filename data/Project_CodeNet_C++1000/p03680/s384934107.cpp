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
	vi arr(n+1);
	for(int i=1;i<=n;i++)cin>>arr[i];
	bitset<100001> b;
	int last = 1;
	bool loop =false;
	while(!loop&&last!=2) {
		if(b[last]){loop=true;break;}
		b[last]=1;
		last=arr[last];
	}
	if(!loop) {
		cout<<b.count();
	} else {
		cout<<-1;
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
