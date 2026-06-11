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
	string s;
	cin>>s;
	int i = s.length()-1;
	while(i>0) {
		if(i-4<0)break;
		string sub = s.substr(i-4,5);
		if(sub=="dream"||sub=="erase") {
			i-=5;continue;
		}
		if(i-5<0)break;
		sub=s.substr(i-5,6);
		if(sub=="eraser"){
			i-=6;continue;
		}
		if(i-6<0)break;
		sub=s.substr(i-6,7);
		if(sub=="dreamer"){
			i-=7;continue;
		}
		break;
	}
	if(i==-1)cout<<"YES";
	else cout<<"NO";
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
