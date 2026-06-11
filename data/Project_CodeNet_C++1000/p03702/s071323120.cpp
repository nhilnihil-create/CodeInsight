#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
	int N;
	ll A,B;
	cin >> N >> A >> B;

	vector<ll> h(N);
	for(int i = 0;i < N;i++)cin >> h[i];

	ll ng = 0;
	ll ok = 1e9;

	while(ok - ng > 1){
		ll mid = (ok + ng) / 2;//爆発させる回数
		ll cnt = 0;
		for(int i = 0;i < N;i++){
			cnt += max(0LL,(h[i] - B * mid + (A - B) - 1) / (A - B));
		}

		if(mid >= cnt)ok = mid;
		else ng = mid;
	}

	cout << ok << endl;
}
