#include <bits/stdc++.h>
#define PW 1000000007
using namespace std;

int main() {
	long long int power = 1;
	int N;
	
	cin >> N;
	for(int i = 1; i <= N; i++) {
		power = i * power % PW;
	}
	cout << power << endl;
}
