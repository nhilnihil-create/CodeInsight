#include<bits/stdc++.h>

using namespace std;

long long ans = 1;
int n;
map<int, int> f;

void factorization(int n){
	for(int i = 2; i <= n; ++i){
		while(n % i == 0){
			f[i]++;
			n /= i;
		}
	}
}

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; ++i) factorization(i);
	for(auto itr = f.begin(); itr != f.end(); itr++){
		ans *= (itr->second+1);
		ans %= 1000000007;
	}
	cout << ans << endl;
}