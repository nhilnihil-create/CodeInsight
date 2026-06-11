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

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

void solve(int test_case) {//209
	int n,m;
	cin>>n>>m;
	unordered_map<int, unordered_set<int>> ma;
	while(m--) {
		int a,b;
		cin>>a>>b;
		if(ma.count(a)==0)ma[a]=unordered_set<int>();
		if(ma.count(b)==0)ma[b]=unordered_set<int>();
		ma[a].insert(b);
		ma[b].insert(a);
	}
	bool contains= 0;
	for(auto i:ma[1]) {
		if(ma[i].count(n))contains=1;
	}
	if(contains)cout<<"POSSIBLE"; else cout<<"IMPOSSIBLE";
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
