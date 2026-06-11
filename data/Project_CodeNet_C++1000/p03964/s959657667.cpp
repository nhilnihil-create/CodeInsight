#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N;
	cin >> N;

	long long A = 1, B = 1;
	for (int i = 0; i < N; i++){
		long long x, y;
		cin >> x >> y;
		long long n = max((A+x-1)/x, (B+y-1)/y);
		A = n * x;
		B = n * y;
	}

	cout << A + B << endl;
	return 0;
}
