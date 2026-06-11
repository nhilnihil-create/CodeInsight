#include <iostream>
using namespace std;
int main(void){
	long long a,b,x,soma;
	cin >> a>>b>>x;
	if(a%x == 0){
		soma = b/x-a/x+1;
	}
	else soma = b/x-a/x;
	cout << soma << endl;
}