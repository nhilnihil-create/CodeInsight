#include <iostream>
using namespace std;

int main(){
	constexpr int mod = 1e9 + 7;
	int n;
	cin >> n;
	long long ans = 1;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x < 2 * i + 1){
			(ans *= i + 1) %= mod;
			n--;
			i--;
		}
	}
	for(int i = 1; i <= n; i++) (ans *= i) %= mod;
	cout << ans << endl;
}