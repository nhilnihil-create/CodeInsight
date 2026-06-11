#include <iostream>
using namespace std;

long long MOD=1000000007;

int main() {
	// your code goes here
	int n;
	cin >> n;
	long long a,b,c;
	int j;
	c = 0;a = 1;
	cin >> j;
	for(int i = 1;i < n;i++){
		if(j < (i-c)*2-1){
			a *= i-c;
			a %= MOD;
			c++;
		}
		cin >> j;
	}
	for(int i = n-c;i > 0;i--){
		a *= i;
		a %= MOD;
	}
	cout << a << endl;
	return 0;
}