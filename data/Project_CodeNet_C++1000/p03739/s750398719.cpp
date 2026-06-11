#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n;
	cin >> n;
	vector<ll> v(n+1);
	v[0] = 0;
	for(int i = 1; i <= n; ++i){
		ll b;
		cin >> b;
		v[i] = v[i-1] + b;
	}
	ll sum = 0;
	ll inc1 = 0;
	bool neg = true;
	for(int i = 1; i <= n; ++i){
		if((neg && v[i] + sum >= 0)){
			inc1 += abs(v[i] + sum) + 1;
			sum -= abs(v[i] + sum) + 1;
		}
		else if(!neg && v[i] + sum <= 0){
			inc1 += abs(v[i] + sum) + 1;
			sum += abs(v[i] + sum) +1;
		}
		neg = !neg;
	}
	sum = 0;
	ll inc2 = 0;
	neg = false;
	for(int i = 1; i <= n; ++i){
		if((neg && v[i] + sum >= 0)){
			inc2 += abs(v[i] + sum) + 1;
			sum -= abs(v[i] + sum) + 1;
		}
		else if(!neg && v[i] + sum <= 0){
			inc2 += abs(v[i] + sum) + 1;
			sum += abs(v[i] + sum) +1;
		}
		neg = !neg;
	}

	cout << min(inc1, inc2);

	
	return 0;
}

