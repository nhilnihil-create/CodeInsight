#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
	int n,sum = 0,ma;
	bool use[10000001] = {};
	cin >> n;
	for(int i = 1;i <= n;i++){
		sum += i;
		if(sum >= n){
			ma = i;
			break;
		}
	}
	for(int i = ma;i >= 1;i--){
		if(n >= i){
			use[i] = true;
			n -= i;
		}
		if(!n) break;
	}
	for(int i = 0;i <= ma;i++){
		if(use[i]) cout << i << endl;
	}
	return 0;
}