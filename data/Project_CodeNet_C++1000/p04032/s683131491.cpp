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

void solve(int test_case) {//213
	string s;
	cin>>s;
	if(s.length()==2) {
		if(s[0]==s[1]){
			cout<<"1 2";
			return;
		}
	}
	for(int i=0;i<s.length()-2;i++) {
		if(s[i]==s[i+1]||s[i]==s[i+2]||s[i+1]==s[i+2]){
			cout<<i+1<<" "<<i+3;
			return;
		}
	}
	cout<<"-1 -1";
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
