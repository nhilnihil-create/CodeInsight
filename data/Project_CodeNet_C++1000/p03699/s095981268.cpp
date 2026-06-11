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
	ll sum=0;
	int mi = INT_MAX;
	while(n--) {
		int val;
		cin>>val;
		sum+=val;
		if(val%10!=0) {
			mi=min(mi,val);
		}
	}
	if(sum%10==0&&mi!=INT_MAX)sum-=mi;
	if(sum%10==0)cout<<0;
	else cout<<sum;
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
