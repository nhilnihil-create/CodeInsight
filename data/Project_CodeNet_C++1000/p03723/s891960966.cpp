#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 100;
int a, b, c; 

int main() {
	
	cin >> a >> b >> c;
	
	
	int num = 0;
	while((a%2==0) && (b%2==0) && (c%2==0)) {
		num++;
		int x = a, y = b, z = c;
		a = (y + z) / 2;
		b = (x + z) / 2;
		c = (x + y) / 2;
		
		if(num >= N) {
			break;
		}
	}
	
	if(num >= N) puts("-1");
	else cout << num << endl;
	return 0;	
} 