#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

int compute(int n, int p){
	int ret = 1;
	while(n){
		ret += n/p;
		n /= p;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);


	int n; cin>>n;
	ll ans = 1;
	for(int i = 2; i <= n; i++){
		int k = i; bool flg = true;
		for(int j = 2; j < k; j++){
			if(k%j == 0){
				flg = false;
				break;
			}
		}
		if(flg)(ans *= compute(n, i)) %= mod;
	}
	cout<<ans<<endl;

	return 0;
}