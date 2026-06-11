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

bool all(string &t,char c) {
	for(char ch:t)if(ch!=c)return false;
	return true;
}

void solve(int test_case) {//209
	string s;
	cin>>s;
	int cnt = INT_MAX;
	vi arr(26,0);
	for(char c:s)arr[c-'a']++;
	for(char c='a';c<='z';c++) {
		if(arr[c-'a']>0) {
			int nc = 0;
			string t=s;
			while(!all(t,c)) {
				nc++;
				string u;
				for(int i=0;i<(int)t.length()-1;i++) {
					if(t[i]==c||t[i+1]==c)u+=c;
					else u+=t[i];
				}
				t=u;
			}
			cnt=min(cnt,nc);
		}
	}
	cout<<cnt;
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
	//prefill();
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
