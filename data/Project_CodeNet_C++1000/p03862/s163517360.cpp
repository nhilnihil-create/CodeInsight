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
	int n,x;
	cin>>n>>x;
	vi arr(n);
	for(int &i:arr)cin>>i;
	ll cnt = 0;
	if(arr[n-1]>x){
		cnt+=arr[n-1]-x;
		arr[n-1]=x;
	}
	for(int i=n-2;i>=0;i--) {
		if(arr[i+1]+arr[i]>x) {
			cnt+=arr[i+1]+arr[i]-x;
			arr[i]=x-arr[i+1];
		}
	}
	cout<<cnt;
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
