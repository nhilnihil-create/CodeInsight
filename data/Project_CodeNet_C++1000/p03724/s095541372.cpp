#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int,int>;
static const ll INF = 1000000000000000000;
static const ll MOD = 1000000007;

int main(){
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		mp[a]++;
		mp[b]++;
	}
	
	for(auto itr : mp){
		if(itr.second % 2 == 1){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}

