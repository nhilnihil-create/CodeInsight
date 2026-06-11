#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	long long acc=0;
	long long i=1;
	while (acc<x){
		acc+=i;
		i++;
	}
	cout << i-1;
	return 0;
}