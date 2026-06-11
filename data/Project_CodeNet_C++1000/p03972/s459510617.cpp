#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;

int main() {
	ll H, W;
	cin >> W >> H;
	vector<pair<ll, int>> v(H+W);
	for(int i=0; i<H+W; ++i){
	    ll c;
	    cin >> c;
	    if(i<W) v[i]=make_pair(c, 0);
	    else v[i]=make_pair(c, 1);
	}
	sort(v.begin(), v.end());
	ll ans=0, hnow=H+1, wnow=W+1;
	for(int i=0; i<H+W; ++i){
	    if(v[i].second==0){
	        ans += v[i].first*hnow;
	        --wnow;
	    }
	    else{
	        ans += v[i].first*wnow;
	        --hnow;
	    }
	}
	cout << ans << endl;
	return 0;
}
