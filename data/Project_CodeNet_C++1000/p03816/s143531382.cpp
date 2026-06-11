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
	unordered_map<int,int> m;
	int n;
	cin>>n;
	while(n--) {
		int val;
		cin>>val;
		m[val]++;
	}
	ll sum = 0;
	bool even = false;
	for(auto a:m) {
		sum++;
		if(a.S%2==0)even=!even;
	}
	if(even)sum--;
	cout<<sum;
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
