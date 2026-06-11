#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> res;
	for (int i = 0; i < n; i+=2)
	{
		res.push_back(a[i]);
	}
	reverse(res.begin(), res.end());
	for (int i = 1; i < n; i+=2)
	{
		res.push_back(a[i]);
	}

	if(n % 2 == 0) reverse(res.begin(), res.end());
	for (int i = 0; i < n; i++)
	{
		cout << res[i];
		if(i == n-1) cout << endl;
		else cout << " ";
	}

	return 0;
}
