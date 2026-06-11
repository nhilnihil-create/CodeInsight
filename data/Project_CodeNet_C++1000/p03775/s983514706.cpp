#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;

int digit(LL num){
	int res = 0;
	while(num > 0) {
		res++;
		num /= 10;
	}
	return res;
}



int main(){
	LL N;cin >> N;
	int ans = 10;
	for(LL i = 1; i * i <= N; i++){
		LL a = 0, b = 0;
		if (N % i == 0) {
			a = i; b = N / i;
			if(a >= b) ans = min(ans, digit(a));
			else       ans = min(ans, digit(b));
		}
	}
	cout << ans << endl;


}












