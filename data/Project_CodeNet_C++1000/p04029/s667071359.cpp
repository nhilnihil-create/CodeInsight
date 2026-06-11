#include<iostream>

using namespace std;

int main() {
	int N, Ans=0;

	cin >> N;
	
	/*for (int i = 1; i = N; i++) {
		Ans += i;
	}*/

	cout << (N*(N+1))/2 << endl;

	return 0;
}