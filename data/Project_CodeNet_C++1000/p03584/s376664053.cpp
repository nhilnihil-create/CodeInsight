#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<ll> b(n);
	ll res = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		if((a[i] | k) == k) res += b[i];
	}
	for(int i = 0; i < 30; i++){
		if(k < (1 << i)) break;
		int num = (k - (1 << i)) | ((1 << i) - 1);
		ll sum = 0;
		for(int j = 0; j < n; j++){
			if((a[j] | num) == num) sum += b[j];
		}
		res = max(res, sum);
	}
	cout << res << endl;
	return 0;
}