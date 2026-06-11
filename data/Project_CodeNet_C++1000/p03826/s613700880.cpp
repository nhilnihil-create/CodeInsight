#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a*b > c*d){
        printf("%d\n",a*b);
	} else {
        printf("%d\n",c*d);
	}
	return 0;
}
