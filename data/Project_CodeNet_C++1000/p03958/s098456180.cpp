#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int k,t;
	cin >> k >> t;
	vector<int> cake(t);
	rep(i,t) cin>>cake[i];
	int nax = -INF;
	int nax_i;
	rep(i,t) {
		if(nax<cake[i]){
			nax = cake[i];
			nax_i = i;
		}
	}
	cake[nax_i]--;
	int before=nax_i;
	int cnt=1;
	for(int i=1;i<k;i++){
		//最大インデックスを探す
		nax = -INF;
		rep(j,t) {
			if(before==j)
				continue;
			if(nax<cake[j]){
				nax = cake[j];
				nax_i = j;
			}
		}
		if(nax<=0)
			break;
		cake[nax_i]--;
		before = nax_i;
		cnt++;
	}
	ll ans=0;
	rep(i,t)
		ans+=cake[i];
	cout << ans << endl;
	return 0;
}

