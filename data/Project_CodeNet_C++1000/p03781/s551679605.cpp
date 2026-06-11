#include <bits/stdc++.h>
using namespace std;

void solve(long long X){
	for(int i = 1;; i++) {
		if(i * (i + 1) / 2 >= X) {
			cout << i << endl;
			return;
		}
	}
}

int main(){	
	long long X;
	scanf("%lld",&X);
	solve(X);
	return 0;
}

