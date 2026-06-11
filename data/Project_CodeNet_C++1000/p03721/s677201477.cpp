#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; ll k; cin>>n>>k;
	map<int, ll> mp;
	for(int i = 0; i < n; i++){
		int a, b;
		cin>>a>>b;
		mp[a] += b;
	}
	for(auto x : mp){
		if(k <= x.second){
			cout<<x.first<<endl;
			break;
		}
		k -= x.second;
	}

	return 0;
}