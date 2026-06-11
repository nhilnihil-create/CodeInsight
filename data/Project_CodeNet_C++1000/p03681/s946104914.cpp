#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
long long modulo = 1000000007;
long long factorial(long long n) {
	if (n == 1) return 1;
  	return (n * factorial(n-1)) % modulo;
}
int main() {
	cin >> n >> m;
  	if (abs(n-m) >= 2) {
    	cout << 0 << endl;
    } else if (n == m) {
    	cout << (2 * (factorial(m) * factorial(n)) % modulo) % modulo;
    }else {
      cout << (factorial(m) * factorial(n)) % modulo;
    }
  	return 0;
}
     