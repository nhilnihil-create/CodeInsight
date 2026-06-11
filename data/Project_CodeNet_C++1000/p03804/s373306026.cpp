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

bool find(vector<string> &a, int ai, int aj, vector<string> &b) {
	for(int i=0;i<b.size();i++) {
		for(int j=0;j<(int)b[i].length();j++) {
			if(a[ai+i][aj+j]!=b[i][j])return false;
		}
	}
	return true;
}

void solve(int test_case) {
	int an,bn;
	cin>>an>>bn;
	vector<string> a(an),b(bn);
	for(string &s:a)cin>>s;
	for(string &s:b)cin>>s;
	bool ans = false;
	for(int i=0;i<=an-bn;i++){
		for(int j=0;j<=an-bn;j++){
			ans=find(a,i,j,b);
			if(ans)break;
		}
		if(ans)break;
	}
	if(ans)cout<<"Yes";
	else cout<<"No";
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
