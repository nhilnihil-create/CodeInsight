#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int counter = 0;
	while(true){
		if (a == b && b == c && a % 2 == 0) {
			cout << -1 << endl;
			break;
		}
		else {
			if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
				int d, e, f;
				d = a, e = b, f = c;
				a = (e + f) / 2;
				b = (f + d) / 2;
				c = (d + e) / 2;
				counter++;
			}
			else {
				cout << counter << endl;
				break;
			}
		}
	}
	
}