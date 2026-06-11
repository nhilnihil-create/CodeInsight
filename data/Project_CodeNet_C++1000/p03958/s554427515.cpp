#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int k, t; cin >> k >> t;
	vector<int> a(t); for(int i = 0; i < t; i++)cin >> a[i];
	int nax = *max_element(a.begin(), a.end()); 

	if(nax <= k / 2) {
		cout << 0 << endl;
		return 0;
	}

	cout << (nax - 1) - (k - nax) << endl;

}