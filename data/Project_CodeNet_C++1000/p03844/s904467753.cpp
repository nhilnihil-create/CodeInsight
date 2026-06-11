#include <iostream>
using namespace std;

int main(void){
	int a, b;
	char c;
	scanf("%i %c %i", &a, &c, &b);
	if(c=='+')cout << a + b << endl;
	else cout << a-b << endl;
}