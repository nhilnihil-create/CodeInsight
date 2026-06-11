#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int n;
	cin >> n;
	map<int,int> mp;
	for(int i=2;i<=n;i++) {
		int k=i;
		for(int j=2; j<i;j++) {
			while(k % j == 0) {
				//cout << k << " " << j << " ";
				mp[j]++;
				k /= j;
			}
		}
		if(k == i) mp[i]++;
	}
	ll ans=1;
	//for(int i=1; i<=n; i++) cout << i << " " << mp[i] << endl;
	for(int i=1; i<=n; i++) {
		ans *= mp[i]+1;
		ans %= 1000000007;
	}
	cout << ans << endl;

  return 0;
}
