#include <bits/stdc++.h>
using namespace std;
long long n , x[300] , y , sol;
bool gen;
int main(){
	cin >> n >> y;
	gen = true;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
		if(x[i] % 2 != 0)gen = false;
	}
	
	if(gen && y == 0){
		cout << (1ll << n) << endl;
	}
	else if(gen && y == 1){
		cout << 0 << endl;
	}
	else{
		cout << (1ll << (n - 1)) << endl;
	}
}