#include <bits/stdc++.h>
using namespace std;
int main() {
	int A, N, K, X, Y;
	cin >> N >> K >> X >> Y;
	if(N <= K){
		A = N * X;
    } else {
		A = K *  X + N * Y - K * Y;
    }
	cout << A;
}