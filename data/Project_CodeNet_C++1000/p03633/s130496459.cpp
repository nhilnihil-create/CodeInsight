#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
	while(a%b>0){
		long long g = a%b;
		a = b;
		b = g;
	}
	return b;
}

int main() {
	int n;
	cin>>n;
	long long num;
	long long multi=1;
	for (int i=0; i<n; i++){
		cin >> num;
		long long g = gcd(multi,num);
		multi = multi/g*num;
	}
	cout << multi << endl;
}
