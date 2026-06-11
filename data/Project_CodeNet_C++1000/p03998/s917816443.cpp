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
	queue<char> arr[3];
	fill(arr,arr+3,queue<char>());
	string a,b,c;
	cin>>a>>b>>c;
	for(char ch:a)arr[0].push(ch);
	for(char ch:b)arr[1].push(ch);
	for(char ch:c)arr[2].push(ch);
	int person = 0;
	while(1){
		if(arr[person].empty()){
			cout<<(char)('A'+person);
			return;
		}
		char top = arr[person].front();
		arr[person].pop();
		person=(top-'a');
		//cerr<<person<<"\n";
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
