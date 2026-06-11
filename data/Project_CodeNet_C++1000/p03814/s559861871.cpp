#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int panjang = s.length();
	int firstA = 0, lastZ = panjang - 1;


	while (s[firstA] != 'A'){
        firstA++;
	}

	while (s[lastZ] != 'Z'){
        lastZ--;
	}

	printf("%d\n", lastZ - firstA + 1);
}
