#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n; vector<int> a(n); for(int i = 0; i < n; i++)cin >> a[i];
	auto itr = unique(a.begin(), a.end());
	a.resize(itr - a.begin());
	n = a.size();
	//for(int i = 0; i < n; i++)cout << a[i];

	if(n < 3) {
		cout << 1 << endl;
		return 0;
	}

	int cnt = 1;
	for(int i = 1; i < n - 1; i++) {

		if((a[i - 1] < a[i] && a[i] > a[i + 1]) || (a[i - 1] > a[i] && a[i] < a[i + 1])) {

			//cout << a[i] << endl;
			cnt++;
			i++;
		}

	}
	cout << cnt << endl;
}