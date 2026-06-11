#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, sum = 0;
	scanf("%lld", &n);
	for(int i = 0;;i++){
		sum += i;
		if(n <= sum){
			printf("%lld\n", i);
			return 0;
		}
	}
	return 0;
}