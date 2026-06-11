#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int w, h;
	cin >> w >> h;
	vector<pair<ll, ll>> v;
	for(int i=0; i<w; i++){
		ll p;
		cin >> p;
		v.push_back(make_pair(p, 0));
	}
	for(int i=0; i<h; i++){
		ll q;
		cin >> q;
		v.push_back(make_pair(q, 1));
	}
	sort(v.begin(), v.end());

	ll ans=0;
	for(int i=0; i<v.size(); i++){
		if(v[i].second==0){
			ans+=(h+1)*v[i].first;
			w--;
		}else{
			ans+=(w+1)*v[i].first;
			h--;
		}
		if(h==0 && w==0) break;
	}

	cout << ans << endl;
	return 0;
}