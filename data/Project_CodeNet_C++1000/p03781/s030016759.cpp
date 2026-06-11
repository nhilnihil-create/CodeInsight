#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n; cin >> n;
	ll s=0, e=100000, m;
	while(m = (s+e)/2, e-s>1){
		if(m*(m+1)/2 >= n) e = m;
		else s = m;
	}
	cout << e;
}
