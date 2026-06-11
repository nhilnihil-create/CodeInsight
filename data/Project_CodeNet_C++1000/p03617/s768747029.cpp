#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll  n, sum = 0,a;
	vector<pair<ll, int>> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> a;
		if(i==0){
			v[i].first=a*8;
		}else if(i==1){
			v[i].first=a*4;
		}else if(i==2){
			v[i].first=a*2;
		}else if(i==3){
			v[i].first=a;
		}
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 4; i++) {
		if (v[i].second == 1) {
			v[i].first/=8;
		} else if (v[i].second == 2) {
			v[i].first/=4;
		} else if (v[i].second == 3) {
			v[i].first/=2;
		}
	}
	cin >> n;
	if (v[0].second == 4) {
		if (n >= 2) {
			sum += (n / 2) * v[0].first;
			if (n % 2 != 0) {
				if (v[1].second == 1) {
					sum += 4 * v[1].first;
				} else if (v[1].second == 2) {
					sum += 2 * v[1].first;
				} else if (v[1].second == 3) {
					sum += 1 * v[1].first;
				}
			}
		} else {
			if (v[1].second == 1) {
				sum += n * 4 * v[1].first;
			} else if (v[1].second == 2) {
				sum += n * 2 * v[1].first;
			} else if (v[1].second == 3) {
				sum += n * v[1].first;
			}
		}
	}else{
		if (v[0].second == 1) {
			sum += n * 4 * v[0].first;
		} else if (v[0].second == 2) {
			sum += n * 2 * v[0].first;
		} else if (v[0].second == 3) {
			sum += n * v[0].first;
		}
	}
	cout<<sum<<endl;
	return 0;
}
