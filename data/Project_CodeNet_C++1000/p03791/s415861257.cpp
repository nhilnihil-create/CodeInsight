#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define MOD (int)(1e9+7)
int x[100000];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> x[i];

	vector<int>index;
	int j = 0;
	for (int i = 1; i < n; i++) {
		if (x[i-1] >= 2 * j + 1)x[i-1] = 2 * j + 1;

		if(x[i]-x[i-1]==1){
			index.push_back(i+1);
			i++;
		}
		j++;
	}
	
	ll ans = 1;
	int cnt = 0;
	for (int i = 0; i < index.size(); i++) {
		ans *= ll(index[i]-cnt);
		ans %= MOD;
		cnt++;
	}
	for (ll i = n - cnt; i >= 1; i--) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans%MOD << endl;

    return 0;
}

