#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a.at(i);
	rep(i,n-1) a.at(i+1)+=a.at(i);
	ll ans=100000000000000000;
	rep(i,n-1) ans=min(ans,abs(a.at(i)-(a.at(n-1)-a.at(i))));
	cout << ans << endl;
}