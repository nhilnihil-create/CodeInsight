#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> V[101010];
ll A[101010];
ll n;

void die() { cout << "NO" << endl; exit(0); }

ll dfs(ll p, ll r)
{
	if(V[p].size() == 1){
		return A[p];
	}
	
	vector <ll> X;
	ll s = 0;
	
	for(ll &t: V[p]){
		if(t != r){
			ll x = dfs(t, p);
			s += x;
			X.push_back(x);
		}
	}
	
	if(s < A[p] || A[p] * 2 < s) die();
	if(*max_element(X.begin(), X.end()) > A[p]) die();
	
	return A[p] * 2 - s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, u, v;
	
	cin >> n;
	
	for(i=1; i<=n; i++){
		cin >> A[i];
	}
	
	for(i=1; i<n; i++){
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	
	if(n == 2){
		cout << (A[1] == A[2]? "YES" : "NO") << endl;
		return 0;
	}
	
	for(i=1; i<=n; i++){
		if(V[i].size() > 1) break;
	}
	
	cout << (dfs(i, 0) == 0? "YES" : "NO") << endl;
	
	return 0;
}