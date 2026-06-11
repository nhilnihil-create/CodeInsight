#include<iostream>
using namespace std;
int main() {
	int n,i=0,a=0;
	cin >> n;
	while (a < n) {
		i = i+1;
		a = a + i;
	}
	std::cout << i;
}