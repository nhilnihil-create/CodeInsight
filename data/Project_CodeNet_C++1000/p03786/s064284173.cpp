#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	vector<int> a(n);
	vector<ll>  sum(n + 1);
	for(int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++) sum[i + 1] += sum[i] + a[i];
	int cnt = 1;
	
	for(int i = n - 1; i >= 0; i--) {
		//cout << sum[i] << endl;
		if(sum[i] * 2 < a[i])break;
		cnt++;

	}
	cout << cnt << endl;
}