#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1005;
const ll mod = 1e9+7;

int prime[maxn];

void findPrime(int n){
	for(int i = 2; i<=n ;i++){
		prime[i] = 1;
	}
	prime[1] = 0;
	for(int i = 2; i*i<= n; i++){
		if(prime[i]){
			for(int j = 2; j<= n/i;j++){
				prime[j * i] = 0;
			}
		}
	}
}

int findexp(int n, int m){
	int sum = 0;
	int num = m;
	while(num <= n){
		sum+=(n/num);
		num *= m;
	}
	return sum;
}

int main(){
	int n;
	cin >> n;
	ll ans = 1;
	findPrime(n);
	for(int i = 2; i <= n; i++){
		if(prime[i] == 1){
			ans = (ans*(findexp(n, i)+1)) % mod;
		}
	}
	cout << ans;
} 