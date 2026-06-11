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
	ll n,k;
	cin>>n>>k;
	bool arr[10];
	fill(arr,arr+10,true);
	while(k--){
		int val;
		cin>>val;
		arr[val] = false;
	}
	while(1) {
		bool flag = true;
		ll val = n;
		while(val>0) {
			if(!arr[val%10]){
				flag=false;
				break;
			}
			val/=10;
		}
		if(flag) {
			cout<<n;
			break;
		}
		n++;
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
