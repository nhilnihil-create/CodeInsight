#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

bool is_prime(int);
void prime_factor(int n, vector<int> &cnt);

int main(){
	int n;
	cin >> n;
	int a = 2;
	long long ans = 1;
	vector<int> cnt(1001, 0);
	while(a <= n){
		prime_factor(a, cnt);
		a++;
	}
	for(int i = 0; i < 1001; i++){
		if(cnt.at(i) > 0){
			if(i != 1){
				ans *= cnt.at(i) + 1;
			}
		}
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

bool is_prime(int n){
	if(n == 1){
		return false;
	}
	if(n == 2){
		return true;
	}
	int divisor = 2;
	while(divisor < n){
		if(n % divisor == 0){
			return false;
		}
		divisor++;
	}
	return true;
}

void prime_factor(int n, vector<int> &cnt){
	while(!is_prime(n)){
		int divisor = 2;
		// cout << "divisor : " << divisor << endl;
		// cout << "n : " << n << endl;
		while(divisor <= n){
			if(is_prime(divisor) && n % divisor == 0){
				cnt.at(divisor)++;
				n /= divisor;
				break;
			}
			divisor++;
		}
	}
	cnt.at(n)++;
	return;
}