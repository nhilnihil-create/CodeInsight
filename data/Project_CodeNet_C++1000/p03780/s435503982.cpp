#include<bits/stdc++.h>
using namespace std;

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	SORT(a);
	reverse(a.begin(), a.end());

	set<ll> st;

	ll ans = 0;
	rep(i, n){
		if(a[i] >= k){
			ans = i + 1;
			continue;
		}
		set<ll> tmp(st);
		tmp.insert(a[i]);
		for(auto it : st){
			if(a[i] + it >= k) ans = i + 1;
      else tmp.insert(a[i] + it);
		}
		st = tmp;
	}

  cout << n - ans << endl;

	return 0;
}