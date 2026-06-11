#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main(){
	int w, h;
	cin >> w >> h;
	vector<ll> p(w), q(h);
	for(int i = 0; i < w; i++) cin >> p[i];
	for(int i = 0; i < h; i++) cin >> q[i];
	vector<P> va;
	for(int i = 0; i < w; i++) va.push_back(P(p[i], 0));
	for(int i = 0; i < h; i++) va.push_back(P(q[i], 1));
	sort(va.begin(), va.end());
	ll res = 0;
	ll num = w + 1, num2 = h + 1;
	for(int i = 0; i < va.size(); i++){
		if(va[i].second == 0){
			res += num2 * va[i].first;
			num--;
		}else if(va[i].second == 1){
			res += num * va[i].first;
			num2--;
		}
	}
	cout << res << endl;
	return 0;
}