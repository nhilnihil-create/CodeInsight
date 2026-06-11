#include <iostream>
using namespace std;

int main() {
	long long N,M;
	cin>>N>>M;
	if (M>N){
		long long x = M-N-N;
		cout << N+x/4;
	}
	else{
		cout << M/2;
	}
}