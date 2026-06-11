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
	string s;
	cin>>s;
	int cnt=0;
	stack<int> st;
	for(char c:s) {
		if(c=='(') {if(cnt<0)st.push(cnt),cnt=0;cnt++;}
		else
			--cnt;
	}
	if(cnt!=0)st.push(cnt);
	while(!st.empty()) {
		int val = st.top();
		st.pop();
		if(val>0) {
			while(val--)s+=")";
		} else {
			while(val++)s="("+s;
		}
	}
	cout<<s;
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
