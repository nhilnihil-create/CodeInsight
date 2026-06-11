#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

vector<vector<int>> grp;

void go(int n,deque<int> &dq,bool b,set<int> &vis){
	if(b) dq.emplace_back (n+1);
	else  dq.emplace_front(n+1);
	for(auto &i:grp[n]){
		if(!vis.count(i)){
			vis.insert(i);
			go(i,dq,b,vis);
			return;
		}
	}
	return;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,e; cin>>n>>e;
	grp.resize(n);
	int s,t;
	For(i,0,e-1){
		cin>>s>>t;
		s--; t--;
		grp[s].emplace_back(t);
		grp[t].emplace_back(s);
	}
	deque<int> dq;
	set<int> vis;
	vis.insert(0);
	go(0,dq,1,vis);
	dq.pop_front();
	go(0,dq,0,vis);
	cout<<sz(dq)<<"\n";
	For(i,0,sz(dq)-1){
		cout<<dq[i]<<" \n"[i==sz(dq)-1];
	}
	return 0;
}



























