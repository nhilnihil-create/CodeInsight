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
	int h,w;
	cin>>h>>w;
	vector<vector<char>> arr(h+2,vector<char>(w+2,'#'));
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)cin>>arr[i][j];
	for(auto a:arr){
		for(char b:a)cout<<b;
		cout<<"\n";
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
