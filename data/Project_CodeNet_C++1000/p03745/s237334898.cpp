#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n; vector<int> a(n); for(int i = 0; i < n; i++)cin >> a[i];
	a.resize(unique(a.begin(), a.end()) - a.begin());
	int cnt = 0;
	n = a.size();

	for(int i = 0; i < n; i++) {
		if(i + 1 < n && a[i] < a[i + 1])
			while(i + 1 < n && a[i] <= a[i + 1])i++;


		else if(i + 1 < n && a[i] > a[i + 1])
			while(i + 1 < n && a[i] >= a[i + 1])i++;
		cnt++;

	}
	cout << cnt << endl;

}