#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int max_x = 101010;
	vector<int> val(max_x, 0);

	rep(i, n){
		int x;
		cin >> x;
		val[x]++;
	}

	vector<int> cnt(m, 0), pair(m, 0);
	rep(i, max_x){
		cnt[i % m] += val[i];
		pair[i % m] += val[i] / 2 * 2;
	}

	ll ans = cnt[0] / 2;
	if(m % 2 == 0){
		for(int i = 1; i < m / 2; i++){
			if(cnt[i] > cnt[m - i]){
				swap(cnt[i], cnt[m - i]);
				swap(pair[i], pair[m - i]);
			}

			ans += cnt[i];
			int sng = cnt[m - i] - pair[m - i];
			if(cnt[i] > sng) {
				ans += (pair[m - i] - (cnt[i] - sng)) / 2;
			}else{
				ans += pair[m - i] / 2;
			} 
		} 
		ans += cnt[m / 2] / 2;
	}else{
		for(int i = 1; i <= m / 2; i++){
			if(cnt[i] > cnt[m - i]){
				swap(cnt[i], cnt[m - i]);
				swap(pair[i], pair[m - i]);
			}

			ans += cnt[i];
			int sng = cnt[m - i] - pair[m - i];
			if(cnt[i] > sng) {
				ans += (pair[m - i] - (cnt[i] - sng)) / 2;
			}else{
				ans += pair[m - i] / 2;
			}
		} 
	}
	
	cout << ans << endl;
}
