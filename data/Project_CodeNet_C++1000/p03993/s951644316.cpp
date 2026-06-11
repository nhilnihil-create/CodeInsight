#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if(a[a[i]] == i) res++;
	}
	cout << res / 2 << endl;
	return 0;
}
