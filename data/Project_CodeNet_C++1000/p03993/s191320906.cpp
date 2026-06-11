#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	REP(i,n) cin >> a[i];
	int ans = 0;
	map<pair<int,int>, int> mp;
	REP(i,n){
		if(mp[make_pair(i,a[i])] != 0) continue;
		if(a[a[i]] == i){
			ans++;
			mp[make_pair(i,a[i])]++;
			mp[make_pair(a[i],i)]++;
		}
	}
	cout << ans << endl;
    return 0;
}


