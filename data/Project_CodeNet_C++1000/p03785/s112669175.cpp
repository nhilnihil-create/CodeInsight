#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n, c, k; cin >> n >> c >> k;
	vector<int> a(n); for(int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 0, cur = a[0];
	int res = 1;


	for(int i = 0; i < n; i++) {
		if(cur + k < a[i] || cnt >= c) {
			cnt = 1;
			cur = a[i];
			res++;
	//		cout << a[i] << endl;
		} else {
			cnt++;
		}
	}

	cout << res << endl;
}