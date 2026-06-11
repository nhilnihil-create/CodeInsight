#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong x;
	cin >> x;

	for(llong i = 1;; i++){
		if(i*(i+1)/2 >= x){
			cout << i << endl;
			break;
		}
	}

	return 0;
}