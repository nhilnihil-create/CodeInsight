#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N, K, X, Y;
	cin >> N >> K >> X >> Y;

	if(N > K){
		cout << K * X + (N - K) * Y << endl;
	}else{
		cout << N * X;
	}
}
