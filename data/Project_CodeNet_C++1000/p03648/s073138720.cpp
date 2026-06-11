#include <iostream>
using namespace std;
long long k, n=50, a;
int main() {
	cin>>k;
	cout<<n<<endl;
	a = k/n - k%n + n-1;
	for(int i=0; i<n; i++) cout<<(i<k%n ? a+n+1 : a)<<' ';
	return 0;
}