#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	int n;
	cin >> n;
	ll res = 0;
	ll p = 1;
	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		if(a == p) p++;
		else if(a < p) continue;
		else{
			ll num = (a - 1) / p;
			res += num;
			if(i == 0) p++;
		}
	}
	cout << res << endl;
	return 0;
}