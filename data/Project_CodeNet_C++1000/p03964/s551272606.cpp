#include <iostream>
using namespace std;

int main(void){
	int t;
	cin >> t;
	long long n[2]= {0, 0};
	while(t--){
		long long a, b;
		cin >> a >> b;
		long long k = max(n[0]/a +(n[0]%a!=0), n[1]/b + (n[1]%b!=0));
		if(!k)k=1;
		n[0] = a*k;
		n[1] = b*k;
	}
	cout << *n +*(n+1) << endl;	
}