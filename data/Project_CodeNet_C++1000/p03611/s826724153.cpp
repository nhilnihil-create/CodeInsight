#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	ll a[100005];
	ll count[100005] = {0};
	bool flag[100005] = {false};
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		count[a[i]]++;
		flag[a[i]] = true;
	}
	ll maxl = 1;
	for(int i = 0; i < 100005; i++){
		maxl = max(maxl, count[i]);
		ll tmax;
		if(flag[i] && flag[i + 1] && flag[i + 2]){
			tmax = count[i] + count[i + 1] + count[i + 2];
			maxl = max(tmax, maxl);
		}
		if(flag[i] && flag[i + 1]){
			tmax = count[i] + count[i + 1];
			maxl = max(tmax, maxl);
		}
		if(flag[i] && flag[i + 2]){
			tmax = count[i] + count[i + 2];
			maxl = max(tmax, maxl);
		}
	}
	cout << maxl << endl;
	return 0;
}