#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[99999], m, sum = 0;
	vector<pair<int, int>> v;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	cin >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		pair<int, int> p = make_pair(a, b);
		v.push_back(p);
	}

	for(int i = 0; i < m; i ++){
		cout << sum - a[v[i].first-1] + v[i].second << '\n';
	}

}
