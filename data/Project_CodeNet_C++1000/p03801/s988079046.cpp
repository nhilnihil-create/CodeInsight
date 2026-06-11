#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<pair<ll,int>> a(n);
	rep(i,n){
		cin >> a.at(i).first;
		a.at(i).second=i+1;
	}
	vector<ll> ans(n+1);
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	a.pb(mp(0,n));
	int k=n;
	rep(i,n){
		k=min(a.at(i).second,k);
		ans.at(k)+=(a.at(i).first-a.at(i+1).first)*(ll)(i+1);
	}
	rep(i,n) cout << ans.at(i+1) << endl;
}