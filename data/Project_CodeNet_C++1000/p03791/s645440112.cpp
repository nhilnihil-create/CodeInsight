#include <bits/stdc++.h>
using namespace std;


int main(){
	int N;
	cin >> N;
	int now = 1;
	int rem = 0;
	long long ans = 1;
	for(int i = 0 ; i < N ; i++){
		int a;
		cin >> a;
		rem++;
		if( a < now ){
			ans *= rem;
			ans %= (int)1e9 + 7;
			rem--;
		}else{
			now += 2;
		}
	}
	for(int i = 1 ; i <= rem ; i++){
		ans *= i;
		ans %= (int)1e9 + 7;
	}
	cout << ans << endl;
}