#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string sen;
	cin  >> sen;
	int count = 0;
	for (int i = 0; i < sen.size(); i++) {
		if (sen[i] == 'p')count--;
	}
	count += (sen.size()) / 2;
	printf("%d", count);
	return 0;
}
