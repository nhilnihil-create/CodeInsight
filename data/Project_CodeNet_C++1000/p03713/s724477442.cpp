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

	int h, w;
	cin>>h>>w;
	if(h%3 == 0 || w%3 == 0){
		cout<<0<<endl;
		exit(0);
	}
	ll ans = min(h, w);
	for(int a = 1; a < w; a++){
		vector<ll> v;
		v.push_back(h*1LL*a);
		v.push_back((h + 1)/2 * 1LL * (w - a));
		v.push_back(h/2 * 1LL * (w - a));
		sort(v.begin(), v.end());
		ans = min(ans, v.back() - v[0]);
	}
	swap(h, w);
	for(int a = 1; a < w; a++){
		vector<ll> v;
		v.push_back(h*1LL*a);
		v.push_back((h + 1)/2 * 1LL * (w - a));
		v.push_back(h/2 * 1LL * (w - a));
		sort(v.begin(), v.end());
		ans = min(ans, v.back() - v[0]);
	}
	cout<<ans<<endl;

	return 0;
}