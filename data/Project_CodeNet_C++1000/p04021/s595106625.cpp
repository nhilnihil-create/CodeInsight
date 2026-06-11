#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<ll> a, b;
	for(int i=0; i<n; i++){
		ll x;
		cin >> x;
		a.push_back(x);
	}
	b=a;
	sort(b.begin(), b.end());

	ll cnt=0;
	for(int i=0; i<n; i++){
		if((lower_bound(b.begin(), b.end(), a[i])-b.begin())%2!=i%2){
			cnt++;
		}
	}
	cout << cnt/2 << endl;
	return 0;
}