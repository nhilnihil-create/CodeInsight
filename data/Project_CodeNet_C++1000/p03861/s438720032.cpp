#include <iostream>

using namespace std;
int main(void){
	long long a, b, c;
	cin >> a >> b >> c;
	long long z= a-a%c;
	cout << (b-z)/c +(z==a) << endl;
}