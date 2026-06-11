#include <iostream>
using namespace std;
typedef long long ll;
ll K, rec[60], ans[60];
const ll N = 50;
int main() {
	cin >> K;
	ll div = K / N, mo = K % N;
	for (ll i=0;i<N;i++)
		rec[i] = div + (i < mo);
	for (ll i=0;i<N;i++) {
		ll sum = 0;
		for (ll j=0;j<N;j++){
			if(i != j)
				sum += rec[j];}
		ans[i] = N * (rec[i] + 1) - sum - 1;
	}
	cout << N << endl;
	for (ll i=0;i<N;i++) cout << ans[i]<<" ";
	return 0;
}
