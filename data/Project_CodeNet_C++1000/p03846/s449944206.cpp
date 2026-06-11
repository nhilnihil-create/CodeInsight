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
	unordered_map<int,int> vals;
	for(int i=0;i<n;i++) {
		int val;
		cin>>val;
		vals[val]++;
	}
	ll sum = 1;
	if(n&1) {
		for(auto m:vals) {
			if(m.F>=n||(m.F&1)){
				goto wrong;
			}
			if(m.F==0&&m.S>1)goto wrong;
			if(m.F!=0&&m.S>2)goto wrong;
			if(m.F!=0){
				sum<<=1;
				sum%=(ll)1e9+7;
			}
		}
	} else {
		for(auto m:vals) {
			if(m.F>=n||!(m.F&1)){
				goto wrong;
			}
			if(m.S>2)goto wrong;
			sum<<=1;
			sum%=(ll)1e9+7;
		}
	}
	cout<<sum;
	return;
	wrong:
	cout<<0;
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
