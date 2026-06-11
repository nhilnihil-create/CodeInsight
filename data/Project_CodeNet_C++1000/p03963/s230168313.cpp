#include <iostream>
using namespace std;

int main(void){
	long long n, k;
	cin >> n >> k;
	int sum = k;
	while(n-->1)sum*=(k-1);
	cout << sum << endl;
}