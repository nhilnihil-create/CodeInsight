#include <bits/stdc++.h>
using namespace std;



int main(){	
	long long B;
	long long C;
	long long D;
	long long N;
	long long A;
	scanf("%lld",&N);
	scanf("%lld",&A);
	scanf("%lld",&B);
	scanf("%lld",&C);
	scanf("%lld",&D);
	bool flg = false;
	for (int i=0; i<=N-1; i++) {
		if (C*i-D*(N-1-i) <= B-A && B-A <= D*i-C*(N-1-i)) {
			flg = true;
			// cout << i << endl;
		}
	}
	if (flg) cout << "YES" << endl; else cout << "NO" << endl;
	return 0;
}

