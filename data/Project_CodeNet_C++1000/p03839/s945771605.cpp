#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, k;
ll br[100001];
ll odg, todg;
int main() {
	cin >> n >> k;
	vector<ll> zbr(n);
	vector<ll> zbrp(n);
	cin >> br[0];
	if(br[0] >= 0) {
		zbrp[0] = br[0];
	}
	zbr[0] = br[0];
	for(int i = 1; i < n; i++) {
		cin >> br[i];
		zbr[i] = zbr[i - 1] + br[i];
		if(br[i] >= 0) {
			zbrp[i] = zbrp[i - 1] + br[i];
		} else {
			zbrp[i] = zbrp[i - 1];
		}
	}
	odg = zbrp[zbrp.size() - 1] - zbrp[k - 1];
	odg += zbr[k - 1];
	for(int i = 1; i < n - k + 1; i++) {
		todg = 0;
		todg = zbrp[zbrp.size() - 1] - zbrp[k - 1 + i];
		todg += zbrp[i - 1];
		if(zbr[k + i - 1] - zbr[i - 1] >= 0) {
			todg += zbr[k + i - 1] - zbr[i - 1];
		}
		//cout << todg << " ";
		odg = max(odg, todg);
	}
	if(odg < 0) {
		odg = 0;
	}
	cout << odg;
}
