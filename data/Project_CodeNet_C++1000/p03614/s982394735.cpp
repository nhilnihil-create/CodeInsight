#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for ( int i=0; i<n; i++ ) {
		cin >> v[i];
		v[i]--;
	}
	int ans=0;
	for ( int i=0; i<n; i++ ) {
		if ( v[i]==i ) {
			if ( i<n-1 ) 
			{
				swap(v[i],v[i+1]);
			}
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
