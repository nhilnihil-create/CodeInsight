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
	int h,w,n;
	cin>>h>>w>>n;
	vi arr(n);
	for(int &i:arr)cin>>i;
	int idx=0;
	bool right = true;
	vector<vector<int>> ans(h, vi(w));
	REP(i,0,h-1) {
		if(right) {
			REP(j,0,w-1) {
				ans[i][j]=idx+1;
				arr[idx]--;
				if(arr[idx]==0)idx++;
			}
		} else {
			for(int j=w-1;j>=0;j--) {
				ans[i][j]=idx+1;
				arr[idx]--;
				if(arr[idx]==0)idx++;
			}
		}
		right=!right;
	}
	for(auto &i:ans) {
		for(auto &j:i)cout<<j<<" ";
		cout<<"\n";
	}
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
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
