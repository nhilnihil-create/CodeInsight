#include <iostream>
using namespace std;
long long f(long long N, long long X){
	if (X == 0){
		return 0;
	} else if (N % X == 0){
		return N - X + (N / X * 2 - 3) * X;
	} else {
		return N - X + ((N - X) / X * 2 - 1) * X + f(N % X + X, N % X);
	}
}
int main(){
	long long N, X;
	cin >> N >> X;
	cout << X + f(N, X) << endl;
}