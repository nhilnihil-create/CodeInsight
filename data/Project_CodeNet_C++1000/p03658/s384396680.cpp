#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main() {
	int x, y,z=0;
	int a[51];
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		cin >>a[i];
			
	}
	for (int i = 0; i < x; i++) {
		for (int j = i + 1; j < x; j++) {
			
			if (a[i] < a[j]) {
				int q = a[i];
				a[i] = a[j];
				a[j] = q;
			}


		}

	}
	for (int i = 0; i < y; i++) {
		z += a[i];

	}cout << z;
	
	return 0;

}