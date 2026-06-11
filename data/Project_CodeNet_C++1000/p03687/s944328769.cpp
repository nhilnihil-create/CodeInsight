#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
string s;
int *ans;
int INF=1e5;



void solve(){
	int n=s.length();
	int ans=INF;
	set<char> c;
	FOR(i,n) c.insert(s[i]);
	for(auto x : c){
		vi v;
		FOR(i,n) if(s[i]==x)
		 	v.PB(i);
		v.PB(n);
		int ans1=v[0];
		for(int i=1;i<v.size();i++){
			ans1=max(ans1,v[i]-v[i-1]-1);
		}
	//	error(x,ans1);
		ans=min(ans,ans1);
	}
	cout << ans;
}

int main(){
	cin >> s;
	solve();	

	return 0;
}