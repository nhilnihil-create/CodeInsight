#include <bits/stdc++.h>

using namespace std;

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const ll mod = 1e9+7;

int main()
{
	const int n=50;
	ll k; cin >>k;
	vector<ll> ans(n);
	
	rep(i,n) ans[i] = n -1 + k/n;
	int pk = k%n;
	
	rep(i, pk){
		ans[i] += n+1;
		rep(j, n) ans[j]--;
	}
	
	
	cout << n <<"\n";
	rep(i,n) cout << ans[i] << (i==n-1? "\n":" ");
	return 0;
}
